inherit ROOM;
void create()
{
        set("short", "����ǽ4");
        set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"eupgate",
  "south"  : __DIR__"ewall10", 
]));
        set("outdoors", "pingan");
	setup();
}
 int valid_leave(object me, string dir) 
{
        object badguy;
 	if ( random(10)>8 && dir == "north" )
{		badguy=new("d/pingan/feizi/feizei");
		badguy->move("d/pingan/gate/ewall11");
        badguy->set("combat_exp",me->query("combat_exp"));
if (me->query_skill("force")>10)
{
        badguy->set_skill("unarmed",me->query_skill("force")*1/2);
        badguy->set_skill("parry",me->query_skill("force")*1/2);
        badguy->set_skill("dodge",me->query_skill("force")*1/2);
        badguy->set_skill("sword",me->query_skill("force")*1/2);
}

        me->fight_ob(badguy);
        me->start_busy(1);
 	return notify_fail("��Ȼ�ӳ�������һ����Ӱ��\n");
}
	else 
	{ 
 	return ::valid_leave(me, dir);
	}
}
