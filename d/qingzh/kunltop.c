// kunltop.c ����ɽ����
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;
void haoqing(object ob);

void create()
{
	set("short",BLINK+HIY "ΡΡ����");
	set("long", HIW @LONG
�����������ɽ�Ķ��壡��ѩ������һƬ��װ��
    վ��������ۿ�ȥ��ֻ��ããȺ����ڽ��£���ɽ���ﾡ�����ţ����˽�ɽ�ཿ��
�����е��������ɣ������뵽�����书����֮ʱ����ͬ���ٴ˷壬����Ⱥ�ۣ���������
�εȵ�����... 
    �뵽����֮���������Ⱥ���(aload)�����������֣�Ψ�Ҷ�...
LONG 
NOR	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"northdown" : __DIR__"kunlun12",
		"southdown" : __DIR__"kunlun11",
	]));
		set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,
	]));	

//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
//	replace_program(ROOM);
}


void init()
{
	object ob;
	
	ob = this_player();
	remove_call_out("haoqing");
	call_out("haoqing",0,ob);

	add_action("do_aload", "aload");
}

void haoqing(object ob)
{
	int imqi,ioqi;
		
	imqi = (int)ob->query("max_qi");
	ioqi = (int)ob->query("qi");
//	ob->receive_damage("qi", ioqi );
        if(ioqi < imqi) 
                 tell_object(ob,HIR"    ��Ȼ����ͻ�䣬��ѩ���������ɲʱ���̹ǣ���ѩ���棬\n"
                                     "�㱻�����������졢����ֱ�����ղŵ�һ������׳־�类�⸱\n"
                                     "�⸱�Ǳ�����ɨ���ټ�ȫ���ˣ�\n"
                                     "    ��ֻ���Ҹ��ܷ紦��������\n"NOR);
//	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));        
}
		
int do_aload(string arg)
{
        object me;
        me = this_player();
	if( random((int)me->query_skill("force")) <= 180) 
	{
//		me->receive_damage("qi", 50);
//		me->receive_wound("qi",  50);
		message_vision(HIR"$N��һ�����˲����ˣ�ֻ��ɽ�ĵ��ѣ�Ǭ����ת...ѩ���ˣ�����  ��...\n"NOR, me);
		switch ( random(2) )
		{
			case 0 :
				me->move(__DIR__"kunlun11");
				break;
			case 1 	:
				me->move(__DIR__"kunlun12");
				break;
		}
		tell_object(me, HIR"�����ѩһ���ɽ�Ϲ���������ֻ���û����޴����ۣ���ѩ���޷���Ϣ������֮��...\n"NOR);
		message("vision", HIR"ֻ��" + me->query("name") + "��ɽ��������Ĵ�ѩһͬ��µµ�ع���������һͷ����ѩ����ֻ�����ų��죬��������������\n"NOR, environment(me), me);
		if((int)this_player()->query("qi")<250) this_player()->die();
       		else this_player()->unconcious();
		return 1;
	}
        if (!arg||arg!="�������֣�Ψ�Ҷ���") return notify_fail("��Ϲ��ʲô��\n");
	message_vision(HIY
		"\n$N��һ�����������Ϊ֮���ݣ�ɽ��Ϊ֮�Ȳʣ����$N���ɾ�һ������ҵ��\n"NOR, this_player());
        if (me->query("shen") > 0)  me->set("shen",(int)me->query("shen") + 100);
        else me->set("shen",(int)me->query("shen") - 100);
	message_vision(HIC
		"\n$N�ж������죬�������ˣ�\n"NOR, this_player());
	return 1;
}
