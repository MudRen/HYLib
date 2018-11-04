#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"��ӥ"NOR, ({ "hawk" }) );
        set("no_get",1);
        set("gender", "����" );
	 set("title",HIY"��Į��ӥ"NOR);
        set("age", 22);
        set("long","һ�����θߴ�ĺ���,��Ϥ������(trainpet)Ұ�޵�������\n");
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
                case 0:
                        say( "��ӥ˵������λ" + RANK_D->query_respect(ob)
                                + "���ҿ��԰���ѵ��Ұ�ޣ�trainpet�����㸶���ӣ�\n");
                        break;
                case 1:
                        say( "��ӥЦ������λ" + RANK_D->query_respect(ob)
                                + "�����ģ����˵ģ�\n");

                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost;
        me = this_player();
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
	if(!arg) return notify_fail("��ӥ��������Ҫʲôѽ����\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("��ӥ��������Ҫʲôѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("��ӥ�������Ǻ�������İɣ���\n");
//okey we identified the target, now the cost:
	cost = to_int(sqrt(to_float((int)pet->query("combat_exp"))))/5;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost/3)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost/8)
	return notify_fail("��Ľ�����������"+chinese_number(cost/8)+"�㡣\n");
	pet->add("combat_exp",cost*50);
	pet->save();
	gold->add_amount(-cost/3);
	me->add("score",-cost/8);
	command("say ���ˣ��´��ٴ�\n");
	return 1;
}
void unconcious()
{
    die();
}
