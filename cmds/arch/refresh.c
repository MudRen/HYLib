// writen by FY@SH-morrison
#include <ansi.h>

int main(object me)
	{
        object *ob_list;
        int i;
	  if( !wizardp(me) )
		return notify_fail("��Ҳ���ʹ�ô����������·ֲ�ʹ����:(\n");
	  message("system",HIR "���·ֲ�����ʹ��������"NOR,users()); 
           ob_list = children("/quest/shenshu/npc/man2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
		message_vision("$NЦ��Ц˵�������Ѿ����֣�������ɣ����ˣ�\n",ob_list[i]);
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }

           ob_list = children("/quest/shenshu/npc/man");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
		message_vision("$NЦ��Ц˵�������Ѿ����֣�������ɣ����ˣ�\n",ob_list[i]);
                    ob_list[i]->move(VOID_OB);
                        destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/shang");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/xia");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book1");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book3");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book4");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book5");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book6");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book7");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book8");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book9");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book10");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book11");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book12");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book13");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book14");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book15");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book16");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book17");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book18");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book19");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book20");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book21");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book22");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book23");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book24");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book25");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book26");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book27");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book28");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book29");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book30");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book31");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book32");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book33");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book34");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book35");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book36");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book37");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book38");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book39");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book40");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book41");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/quest/shenshu/book42");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
           ob_list = children("/clone/misc/findbook");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        ob_list[i]->move(VOID_OB);destruct(ob_list[i]);
               }
	  TASK_D->init_dynamic_quest(1);
	  message("system",HIG "������ʹ�����·ֲ����\n"NOR,users()); 
          return 1;
	}
        	
 int help(object me)
{
  write(@HELP

refresh �������������²����У���ɺ�û��ɣ���ʹ�����������

HELP
    );
return 1;
}

