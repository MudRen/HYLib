#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���߽���Ժ��ӭ����һ����԰���������ۡ��������ſ�
�޴��ޱȵļ�ɽ (jiashan)��ˮ�ص����������˻��ݣ�������
�У���ľ֦Ҷï�ܣ��ڸ��˴���Ժ�ӡ��ϱ�һ��������ľ��
���ȣ�ͨ����ҵĺ�����
LONG);
	set("exits", ([
  		"south" : __DIR__"miaojia_zoulang2",
	]));

        set("item_desc", ([
                "jiashan" : WHT "\n�㷢�ּ�ɽ����⻬�ޱȣ���"
                            "��������ʲô���֡�\n" NOR,
        ]));

        set("no_clean_up", 0);
        set("coor/x", -180);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_think", "think");
}

int do_think(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if (! living(me)) return 0;

        if (! living(this_player()) || arg != "jiashan")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("lengyue-shengong", 1) < 1)
                return notify_fail("�㷢�ּ�ɽ�������صĶ������Լ���ѧ"
                                   "���޸�ϵ��������������\n");

        if ((int)me->query_skill("lengyue-shengong", 1) < 100)
                return notify_fail("�㷢�ּ�ɽ�������ص��ڹ��ķ�������"
                                   "�£��Լ�ȫȻ�޷�������\n");

        if ((int)me->query_skill("lengyue-shengong", 1) > 180)
                return notify_fail("�㷢�ּ�ɽ�������ص��ڹ��ķ����ڷ�"
                                   "ǳ�����Լ��Ѻ��ް�����\n");

        if (! me->can_improve_skill("lengyue-shengong"))
                return notify_fail("������ʵս���鲻���Ե�ʣ���������"
                                   "����ɽ�ϼ��ص����ݡ�\n");

        if ((int)me->query("jing") < 80)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        me->receive_damage("jing", 60);

        if (me->can_improve_skill("lengyue-shengong"))
	{
                // �츳��ӱ�����ж��ٶ�
                if (me->query("special_skill/clever"))
                	me->improve_skill("lengyue-shengong", me->query("int") + 5);
                else
                        me->improve_skill("lengyue-shengong", me->query("int"));
        }

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ����ɽ�������ص��ķ���"
                       "��������\n" NOR, me);
        write(HIC "��ԡ������񹦡������µ�����\n" NOR);
        return 1;
}
