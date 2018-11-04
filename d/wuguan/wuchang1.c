//cool 98.4.18

#include <ansi.h>
inherit ROOM;
int do_da(string arg);

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
���Ǽ���ķ��ӣ�ʮ�ֿ����������������ﺹ��䤱��Ŀ����Ź���
������һЩ�����õĹ��ߣ�ǽ�߰���һ��ľ��׮(muren zhuang)��
LONG);
	set("exits", ([
	       "north" : __DIR__"wuchang3",
	       "east" : __DIR__"lang1",
        ]));
        set("item_desc", ([
	  "muren zhuang" : "һ��ľ׮������ľ�˵����ӹ̶��ڵ��ϣ����˻���(da)������\n",
	]));
        set("outdoors", "���");
        set("objects", ([
           __DIR__"npc/xxdizi" : 1,
        ]));
	setup();
}

void init()
{
        add_action("do_da", "da");
        
}
int do_da(string arg)
{
        object me;
        int costj, costq;

        me = this_player();
        if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר��������\n");
        if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
        if( objectp( me->query_temp("weapon")) ) return notify_fail("ֻ�п��ֲ��ܴ�ľ��׮��\n");
        if (!arg || arg != "muren zhuang") return notify_fail("��Ҫ��ʲô��������\n");
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
              message_vision("$N��һ�ɣ�һ��С���Դ�ײ����ľ��׮�ϣ�\n",me);
              me->unconcious();
              return 1;
              }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$Nվ������������ȭ����ʼ��ľ��׮�Դ�������\n", me);
        if ( (int)me->query_skill("cuff", 1) < 30 && random(10)>6 ){  
              write(HIM"���ں�ľ��׮�ĶԴ��������˲��ٻ���ȭ����\n"NOR);
              me->improve_skill("cuff", (int)(me->query("int") / 5));
              }
        if ( (int)me->query("combat_exp") < 30000) {
        if ( (int)me->query("potential") <  10000) {
	     me->add("potential",random(2));
             }           
             me->add("combat_exp",random((int)(me->query("str") / 10)));
             }
        return 1;
}
