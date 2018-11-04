// Room: /u/dubei/u/gumu/jqg/qb
// by dubei
#include <ansi.h>;
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ͱ�");
	set("long", @LONG
������һ���ƽ̹����ʯ��ֻ��һ�����������ұ���ģģ������
������(zi)���ƺ�������������ȥ�ģ��������Ϊʱ���Զ��
ֻ����ǿ�ϵá�
LONG
	);
      set("item_desc", ([
          "zi" : HIW " ʮ������ڴ���ᣬ���������ʧ��Լ��
С��Ů����������ɣ�������ǧ��������ۡ�\n"NOR,]));
        set("outdoors", "����");
	setup();
 
}
void init()
{
        add_action("do_pa", "pa");
        add_action("do_jump", "jump");
}
int do_pa(string arg)
{
       object me = this_player();

       if( !arg || arg == "" || arg !=  "gudi") return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 20) 
       return notify_fail("�����ϸ���̫�࣬������ȥ��\n");
 
       if((int)me->query_skill("dodge",1) < 100 )  
       return notify_fail("����Ŀǰ���Ṧ��Ϊ����������ȥ��\n"); 
        message_vision("$N��ס��ʯ��С�ĵ�������ȥ��\n", me);
       me->move(__DIR__"gd1");
       tell_room(environment(me), me->name() + "����������������\n", ({ me }));
       return 1;
       
}
int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "duanchang ya" ) return 0;
       if ( !arg ) return 0;
 
        
       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 20) 
       return notify_fail("�����ϸ���̫�࣬�޷�����ȥ��\n");
 
       if((int)me->query_skill("dodge",1) < 100 )  
       return notify_fail("����Ŀǰ���Ṧ��Ϊ���޷�����ȥ��\n"); 
       message_vision("$N����������Ķϳ��¹�ȥ��\n", me);
       me->move(__DIR__"dcy");
       tell_room(environment(me), me->name() + "���ͱ����˹�����\n", ({ me }));
       return 1;
}