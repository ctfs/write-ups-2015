__int64 __fastcall mainroutine(__int64 a1, __int64 a2)
{

   (...)

   while ( 1 )
   {
     src = off_602540[v13];
     if ( !src )
       break;
     v12 = time(0LL);
     sleep(*(&seconds + v13));
     v11 = (unsigned __int64)time(0LL) - v12;
     sprintf(&s, "%d", v11, v4);
     strcpy(&dest, src);
     strcat(&dest, &s);
     if ( !sub_400D65(&dest, (unsigned int)dword_602300[v13], &v8) )
     {
       LODWORD(v3) = sub_400DDD(&dest);
       printf(v3);
       dword_602BF8 = 0;
     }
     ++v13;
   }
   putchar(10);
   result = 0LL;
 }
 return result;
}
