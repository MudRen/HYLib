// Room: /u/dubei/u/gumu/jqg/ht1
// by dubei
 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "̶��");
	set("long", @LONG
������ɭɭ�Ķ��������������̶ˮ�����˸е�͸�ǵĺ��䡣
Զ����һ˿�����⡣
LONG
	);
        setup();
}
void init()
{
        add_action("do_fu", "fu");
        add_action("do_qian", "qian");
}
int do_fu(string arg)
{
       object me = this_player();

       if( !arg || arg == "" || arg !=  "up") return 0;
  
        message_vision("$Nһ�����٣�������ȥ��\n", me);
       me->move(__DIR__"gd1");
       tell_room(environment(me), me->name() + "ʪ���ܵĴ�̶�����˳�����\n", ({ me }));
       return 1;
       
}
int do_qian(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "liang guang" ) return 0;
       if ( !arg ) return 0;
       if (!living(me)) return 0;
       message_vision("$N�����������˹�ȥ��ԽǱԽ�������ʱ����������һ�죬�����ˮ�档\n", me);
       me->move(__DIR__"gd2");
       tell_room(environment(me), me->name() + "��̶ˮ��ð�˳�����\n", ({ me }));
       return 1;
}