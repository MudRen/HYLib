//ls.c
//By Bill 2000/5/3
#include <ansi.h>
#include <localtime.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string dir,dir1,result,cwd = me->query("cwd");
        mixed *files,times;
		        mixed *file,*arrge;

        int i,j,e,d,c,w,fc,dc,bytes,*dis;

        seteuid(geteuid(this_player(1))); 
        dir = resolve_path(cwd, arg);
        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )   dir += "/";
        files = get_dir(dir, -1);

        dir = dir[0..strsrch(dir,"/",-1)];
        if( !sizeof(files) ){
                if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
                else return notify_fail("û�����Ŀ¼�����ļ���\n");
        }
        write("\n"+HIY+"��"+MUD_NAME+"��"NOR+"�ļ�Ŀ¼��"  + "\n");
		        write("\n"+HIR+"----------------------------------------------------------------------------"NOR+" "  + "\n");
	        result ="\n"NOR;
        for(i=0;i<sizeof(files);i++){
                files[i][0] = resolve_path(dir,files[i][0]);
                if(!(int)SECURITY_D->valid_read(files[i][0], me)) continue;
                times = localtime(files[i][2]);
                if(files[i][1] == -2) result += sprintf(HIW"<  Ŀ¼ >"NOR"     %-=40s\n",
                        files[i][0]);
                else result += sprintf(HIW"%-9d"NOR"     %-=40s\n",
                                files[i][1],files[i][0]);
                }
   
	    i = sizeof(files);
        c = 0;
        w = 0;
        dis=allocate(i);
        while(i--) {
                dir1=files[i][0];
            //    dir1=(arg[strlen(arg)-1]=='/')?(arg+dir1):(arg+"/"+dir1);
               dir1=(dir1[0]=='/')?dir1:"/"+dir1;
                if(files[i][0]=="."||files[i][0]=="..")
                        continue;//ֱ���������ˣ���Ȼ".."���ǲ���������ʾ
                if(file_size(dir1)==-1)
                        dis[d++]=i+1;
                if(files[i][1]==-2) {
                        files[i][0] =files[i][0]+"/";
                        c++;
                }
  
        }
		fc = sizeof(files) - c;
        dc = c;
		bytes = c+c;
		j = sizeof(files);
   
        if (sizeof(files)) {
                for(i=0; i<j; i++) {
         
                  bytes += files[i][1];
                                    }
		}

		 printf("\n                          "+WHT"%4d"NOR+"���ļ�       "+WHT"%d"NOR+"���ֽ�", fc, bytes);
         printf("\n                          "+WHT"%4d"NOR+"��Ŀ¼", dc);
        write("\n"+HIR+"----------------------------------------------------------------------------"NOR+" "  + "\n");
		write("\n"+HIR+"Ŀ¼���ֽ�             Ŀ¼���ļ�����                     ����޸�����      "NOR+" "  + "\n");

		 me->start_more(result);
		write("\n"+HIR+"----------------------------------------------------------------------------"NOR+" "  + "\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: ls [<·����>]
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������
��ɫĿ¼Ϊ��Ȩ�޶�ȡ��Ŀ¼��
HELP
        );
        return 1;
}
