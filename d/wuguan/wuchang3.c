//cool 98.4.18
#include <ansi.h>
inherit ROOM;
int do_chuo(string arg);
int do_ti(string arg);
int do_pai(string arg);
int do_zhua(string arg);

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
���Ǽ���ķ��ӣ�ʮ�ֿ����������������ﺹ��䤱��Ŀ����Ź���
������һЩ�����õĹ��ߣ�ǽ�ǹ���һ�Ŵ���ɳ����shadai)��һЩ����
����ɳ��������
LONG);
        set("outdoors", "���");
	set("exits", ([
	       "south" : __DIR__"wuchang1",
	       "north" : __DIR__"lang3",
        ]));
        set("item_desc", ([
	     "shadai"  :  "һ����ɳ�������������ϣ������кܶ���;���������������Ĵ�(da)��\n",
	]));
        set("objects", ([
           __DIR__"npc/nvdz" : 1,
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
        if (me->is_busy()) return notify_fail("��������æ����!\n");
        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר��������\n");
        if ( !living(me)) return notify_fail("�㷢����? \n");
        if( objectp( me->query_temp("weapon")) ) return notify_fail("ֻ�п��ֲ��ܴ�ɳ����\n");
        if ( !arg || arg != "shadai" ){    
            message_vision("$N�����ָ�ڿ����Ҵ��ұ�һͨ�������ڹ�����\n",me);
            return 1;
            }
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
             message_vision("$N�������ͣ�һ����С�ģ�ͷ������ǽ�ϣ�\n",me);
             me->unconcious();
             return 1;
             }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$N���˸�������������Ȼ��һ����ɳ����ȥ��\n", me);
        if (random(10)>6 ){
             write(HIM"ɳ������ҡ�Σ��㲻֪������������Щ�����书��\n"NOR);  
             switch(random(4)){
                case 0: me->improve_skill("finger", (int)(me->query("int") / 10));
                case 1: me->improve_skill("leg", (int)(me->query("int") / 10));
                case 2: me->improve_skill("claw", (int)(me->query("int") / 10));
                case 3: me->improve_skill("strike", (int)(me->query("int") / 10));
                }
             }
        if ( (int)me->query("combat_exp") < 30000) {
        if ( (int)me->query("potential") <  10000) {
	     me->add("potential",random(2));
             }           
             me->add("combat_exp",random((int)(me->query("str") / 10)));
             }
        return 1;
}
