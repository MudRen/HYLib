#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"���µ�һ��"NOR); 
        set("long", @LONG
����������µ�һ�塪����������壡��
����Ⱥɽ��Զ���Ĵ��ԭ���ڽ��¡���ɫ�Ĳ��������ڽ����¿������紿��������
����ɫ�ı�������ʶ�һ�����ӷ嶥������˷�����ȥ����Ƕ�ڽ�׵�ɽ���ϡ���
���侢����ѩ���ˣ�����������ɽ�ӣ��������أ�׳־���ƣ�������������֮
�ģ���Х���������ƷŸ衣
    �뵽����֮���������Ⱥ���(aload)�����������֣�Ψ�Ҷ�...
LONG); 
        set("type","street");
        set("exits",([
        "down":__DIR__"bingao",
        ]) );
	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 6,
	]));          
        set("outdoors", "guanwai");
        set("no_death_penalty",1);
        set("coor/x",-1280);
        set("coor/y",-110);
        set("coor/z",888); 
        setup();
       
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
if (userp(ob))
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

	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));        
}
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
				me->move(__DIR__"bingao0");
				break;
			case 1 	:
				me->move(__DIR__"bingao3");
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
        if (me->query("shen") > 0)  me->set("shen",(int)me->query("shen") + 1000);
        else me->set("shen",(int)me->query("shen") - 1000);
	message_vision(HIC
		"\n$N�ж������죬�������ˣ�\n"NOR, this_player());
	return 1;
}
