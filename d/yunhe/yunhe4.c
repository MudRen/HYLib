// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "�����˺�" NOR);
    set("long", HIY @LONG
�����������������ھ����˺��ϡ���������ബֻ����������
����໪ɽ��С���Ѿ��ܽ��ˣ����Կ���һЩ��Ů���ںӱ�ˢϴ
�·���������Ƥ��С�����ں�����Ӿ��һƬ������ũ�ҷ�⡣
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


void init()

{	
	object me=this_player();
	
	tell_object(me, CYN "\n\n\n���������򰶱߿�ȥ,�Ϳ쵽��...\n\n\n" NOR ) ;
	call_out("goto",6, me);
}
void goto(object me)

{	 if( (int)me->query_temp("exit") )
         {
	message("vision", "����˵����ɽ�嵽�����ϰ��ɡ������漴��һ��̤�Ű���ϵ̰���\n"
			   "���Ų������˰�\n\n", me );
	 me->move(__DIR__"matou3");
	 message("vision",me->name()+"�Ų��Ӵ������ϰ�����\n",environment(me), ({me}) );
	}
       
}

