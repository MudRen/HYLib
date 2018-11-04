#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����һ��");
        set("long", @LONG
�����е�һ��ʥ�ء�������ʿͨ�������˴������д���䣬Ѱ��֪����
ֻ��������Щʫ�䣬Ҳ��֪����λ�������µ��ֱʡ��ڰ�����һ��ʯ
ͷ���Ͽ̣�
[34m
                       Ц��Ҷ�俴���ƣ�
                       ���׻�������ˮ��
                                       
[37m
���������������������ĵط�����(levelup)�����ĵȼ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"wudao4",
]));
       
  set("objects", ([ /* sizeof() == 4 */
  "/d/city/npc/xunbu" : 1,
  "/clone/npc/testnpc" : 1,
  "/d/migong/obj/testnpc2" : 1,
]));
	set("citybiwu",1);
	set("no_death_penalty",1);
	set("no_dazuo",1);
	       
	setup();
}
void init()
{
	add_action("do_levelup","levelup");
        add_action("do_quit","exercise");
        add_action("do_quit","get");
        add_action("do_quit2","quit");
        add_action("do_quit2","exit");
        add_action("do_quit2","exercise");
        add_action("do_quit2","dazuo");
        add_action("do_quit2","learn"); 
        add_action("do_quit2","xue");
        add_action("do_quit2","respirate");
        add_action("do_quit2","tuna"); 
        add_action("do_quit2","persuade");
        add_action("do_quit2","practice");
        add_action("do_quit2","lian"); 
        add_action("do_quit2","study");
        add_action("do_quit2","du");
        add_action("do_quit2","teach");
        add_action("do_quit2","jiao");
}
int  do_levelup(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
        if( !arg ) return notify_fail("��Ҫ����ʲ��������\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("������û�н��ӡ�\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("������û������������\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
        if( ob->query("equipped") )
        return notify_fail("�㲻�ɼ�װ�����˵�������\n");
        if( !ob->query("ownmake") )
        return notify_fail("��ֻ�ɼ��Լ������������\n");
        if( ob->query("armor_type"))
        return notify_fail("����������ȥ��ĵط���jijia������\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("������������޷�����������\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("�����ڵ�����̫�����޷�����������\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("�����ڵľ����޷����У����ܶ���������\n");
	if( (int)me->query("score") < 100 )
		return notify_fail("�����ڵĽ����������������ܶ���������\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 20 )
		return notify_fail("���Ǳ�ܲ������޷�����������\n");
	j = (int)me->query("weapon/lv");

	if(j<6) cost = 20*j;
	else if(j<11) cost = 30*j;
	else if(j<16) cost = 40*j;
	else if(j>500) cost = 200*j;
	else cost = 60*j;
        if((int) gold->query_amount() < 100)
        return notify_fail("������û����100�����ӡ�\n");

        if((int) gold->query_amount() < cost)
        return notify_fail("������û����" + sprintf("%d",cost)+ "�����ӡ�\n");
        gold->add_amount(-cost);
        me->start_busy(2);
	me->add("bellicosity",cost);
	seteuid(ROOT_UID);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("score",-100);
	me->add("learned_points", 20);
	me->set("weapon/lv", j+1);
	me->save();
	reload_object(ob);
	message_vision(HIY "�������һ����һ���������$N��"+ob->name()+HIY"�������ˣ�\n" NOR,me);
	message_vision(HIG "$N��"+ob->name()+HIG"�ĵȼ�����ˣ�\n" NOR, me);
        seteuid(getuid());
	return 1;
}

int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"�����ĵı���ɣ�\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"�����ĵı���ɣ�\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"�����ĵı���ɣ�\n");
        return 1;
}
