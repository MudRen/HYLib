//cool 98.4.18

#include <ansi.h>
inherit ROOM;

int do_tiao(string arg);

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
����¶�����䳡���ö�����������������ţ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ��򣬳��ӵĶ�����һ��
ɳ��(shakeng)��
LONG);
	set("exits", ([
	       "north" : __DIR__"wuchang4",
	       "west" : __DIR__"lang2",
        ]));
        set("objects", ([
           __DIR__"npc/mjbz" : 1,
        ]));
        set("item_desc", ([
	    "shakeng"  :  "����һ����ɳ�ӣ�����С������ɳ����������(tiao)Ծ�š�\n",
	]));
        set("outdoors", "���");
	setup();
}

void init()
{
        add_action("do_tiao", "tiao");
        
}
int do_tiao(string arg)
{
        object me;
        int costj, costq;

        me = this_player();
        if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר��������\n");
        if ( !living(me)) return notify_fail("�㷢���ˣ�\n");

        if ( !arg || arg != "shakeng" ) return notify_fail("���ڳ�����ı������˰��죬���˻���Ϊ�㷢�񾭣�\n");
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
               message_vision("$N����һ���������һ������ɳ����ˤ�˸�����ʺ��\n",me);
               me->unconcious();
               return 1;
               }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$N���ӵ����������ڴ�ɳ���з����������¡�\n", me);
        if ( (int)me->query_skill("dodge", 1) < 20 && random(10)>6 ){  
               write(HIM"�㲻�ϵ���ɳ�������ţ��Լ��Ļ����Ṧ������ߣ�\n"NOR);
               me->improve_skill("dodge", (int)(me->query("int") / 4));
               }
        if ( (int)me->query("combat_exp") < 30000) {
        if ( (int)me->query("potential") <  10000) {
	     me->add("potential",random(2));
             }           
             me->add("combat_exp",random((int)(me->query("str") / 10)));
             }
        return 1;
}
