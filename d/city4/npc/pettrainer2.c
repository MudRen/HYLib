#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"ľӥ"NOR, ({ "hawk" }) );
        set("no_get",1);
        set("gender", "����" );
	set("title",HIC"��Į��ӥ"NOR);
        set("age", 32);
        set("long","���Ը��ƶ�������ʱ����(trainpet)��\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "trainpet");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
               
                case 1:
                        say( "ľӥЦ�����ⲻ�����������ˣ�\n");
                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost;
	string which;
        me = this_player();
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
	if(!arg) return notify_fail("ľӥ��������Ҫʲôѽ����\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("ľӥ��������Ҫʲôѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("ľӥ�������Ǻ�������İɣ���\n");
	switch (random(2)){
	case 0: which = "max_jing"; break;
	case 1: which = "max_qi"; break;
				}	
//okey we identified the target, now the cost:
	cost = (int) pet->query(which) / 10;
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost/2)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost/8)
	return notify_fail("��Ľ�����������"+chinese_number(cost/8)+"�㡣\n");
	pet->add(which,10);
	pet->save();
	gold->add_amount(-cost/2);
	me->add("score",-cost/8);
	command("say ��͵��ˣ�\n");
	return 1;
}
void unconcious()
{
    die();
}
