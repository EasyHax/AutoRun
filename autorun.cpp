#include <windows.h>
#include <iostream>

#define PRINT_SUCCESS(s)	 std::cout << "[+] " << s << std::endl;
#define PRINT_INFORMATION(s) std::cout << "[*] " << s << std::endl;
#define PRINT_ERROR(s)		 std::cout << "[!] " << s << std::endl;

void SendKey( WORD VK, bool bKeyDown ) {

	INPUT input;
	input.type     = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey( VK, MAPVK_VK_TO_VSC );

	input.ki.time        = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.dwFlags = bKeyDown ? NULL : KEYEVENTF_KEYUP;

	input.ki.wVk = VK;

	SendInput( 1, &input, sizeof( INPUT ) );
}

void main( void ) {

	//PRINT_INFORMATION( "Waiting for Hyperscape to run ..." );
	//HWND hTargetWindow = nullptr;

	//while ( !(hTargetWindow = FindWindow( NULL, L"Hyperscape" )) ) { Sleep( 100 ); }
	//PRINT_SUCCESS( "Hyperscape is running!" );
	//PRINT_SUCCESS( hTargetWindow );
	
	bool bKeyPressed = false;

	while ( true ) {
		if ( GetAsyncKeyState( VK_SHIFT ) & 0x8000 ) {
			if ( bKeyPressed ) {
				SendKey( 0x50, false );
				bKeyPressed = false;
			}		
		} else {
			if ( !bKeyPressed ) {
				SendKey( 0x50, true );
				bKeyPressed = true;
			}
		}
		Sleep( 10 );
	}
}
