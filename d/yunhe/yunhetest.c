// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "�����˺�" NOR);
    set("long", HIY @LONG
�����������������ھ����˺��ϡ���������ബֻ����������
���������ݲ�Զ�����Ժ��ϻ��в��ٻ��������ϲ�ʱ���������
���������ο͵���Ц������֪��������������·�Ҳ����Ⱦ�ˣ�
���������ˡ�����ʮ��ᣬ��������ݡ���仰��
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


   

void init()

{	

	 	 add_action("do_look", "look");
	 
        }


int do_look()
{  
        return notify_fail("С��\n\tһҶС�ۣ����Ҳ�������������ˡ�һ������������ֳ�\n����ݣ������ļ��Ŵ���\n");
    
}

