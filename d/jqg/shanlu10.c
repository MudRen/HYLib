// shanlu10.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIY"�ϳ���"NOR);
    set("long", @LONG
������������ȣ�����ɽ��������嶥��������֮�У���֪��ͷ�����ϳ�
�¡�ǰ��羰���ģ�ֻ�����ʵ��̫�գ�ɽʯ��������׵�����Ԩ��������
�ײ������ˡ�
LONG
     );

    set("exits", ([ 
	"westdown"  : __DIR__"shanlu9",        	
    ]));
    set("outdoors", "�����");
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
       write("����ϸ�������ܡ������ڲ�Զ����һ��ͻ�������ͱڣ�������ǿ����\n");
       this_player()->set_temp("jqg_look1", 1);
       return 1;     
}

int do_jump(string arg)
{
       object me,*ob;
       int i;
       me = this_player(); 
       if (arg != "qiaobi" ) return 0;
       if ( !arg ) return 0;
       if (!me->query_temp("jqg_look1"))
          return notify_fail("��Ҫ����������\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
         return notify_fail("�����ϱ���һ���ˣ��޷���������ȥ��\n");      
       if (!living(me)) return 0; 
       if((int)me->query_skill("dodge",1) < 100 )  
           return notify_fail("����Ŀǰ���Ṧ��Ϊ���޷�����ȥ��\n"); 
       message_vision("$N������ǰ����ͱ����˹�ȥ��\n", me);
       me->move(__DIR__"duanchang");
       tell_room(environment(me), me->name() + "�Ӷϳ������˹�����\n", ({ me }));
       me->delete_temp("jqg_look1");
       return 1;
}
