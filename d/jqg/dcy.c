// Room: /u/dubei/u/gumu/jqg/dcy
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
�����Ǿ���Ⱥ�ɽ�嶥���˼�������վ����ǰ��������ȣ���������
ãã��
LONG
	);

	set("exits", ([
                "southdown" : __DIR__"sl3",
	]));
 

        set("outdoors", "xiangyang");
	setup();
 
}
void init()
{
        add_action("do_look", "look");
        add_action("do_jump", "jump");
}
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "ya") return 0;
             write(
             "����ϸ�������ܡ������ڲ�Զ����һ��ͻ�������ͱڣ�������ǿ����\n"
             );
             this_player()->set_temp("jqg_look1", 1);
             return 1;
       
}
int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "qiaobi" ) return 0;
       if ( !arg ) return 0;
       if (!me->query_temp("jqg_look1"))
        return notify_fail("��Ҫ����������\n");
        
       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       return notify_fail("�����ϸ���̫�࣬�޷�����ȥ��\n");
 
       if((int)me->query_skill("dodge",1) < 100 )  
       return notify_fail("����Ŀǰ���Ṧ��Ϊ���޷�����ȥ��\n"); 
       message_vision("$N������ǰ����ͱ����˹�ȥ��\n", me);
       me->move(__DIR__"qb");
       tell_room(environment(me), me->name() + "�Ӷϳ������˹�����\n", ({ me }));
       me->delete_temp("jqg_look1");
       return 1;
}
