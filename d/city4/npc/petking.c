#include <ansi.h>
inherit NPC;
void create()
{
        set_name(YEL"ӥ��"NOR, ({ "hawkking" }) );
        set("gender", "����" );
        set("no_get",1);
	 set("title",HIY"��ӥ֮��"NOR);
        set("age", 62);
        set("long","һ�����θߴ�ĸ���,��Ϥ��Ұ��(up)����ɳ���������\n");
        set("combat_exp", 1500000);
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
        add_action("do_train", "up");
        add_action("do_train2", "upbest");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "ӥ��˵������λ" + RANK_D->query_respect(ob)
                                + "���ҿ��԰�������Ұ�ޣ�up�����㸶���ӣ�\n");
                        break;
                case 1:
                        say( "ӥ��Ц������λ" + RANK_D->query_respect(ob)
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
	if(!arg) return notify_fail("ӥ����������Ҫʲôѽ����\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("ӥ����������Ҫʲôѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("ӥ���������Ǻ�������İɣ���\n");

//okey we identified the target, now the cost:
	cost = to_int(sqrt(to_float((int)pet->query("combat_exp"))))/3;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost/2)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost/4)
	return notify_fail("��Ľ�����������"+chinese_number(cost/4)+"�㡣\n");

//to_int(sqrt(to_float((int)pet->query("combat_exp"))))/5;
	pet = present(arg,environment());
        if( pet->query("up1") >= 1 )
                return notify_fail("��ĺ����Ѿ���������.\n");

	pet = present(arg,environment());
//	if(pet->query_skill("puyaogedou") < 150)
//	return notify_fail("��ĵĺ������ҧ�񶷵ȼ�������\n");
	if(pet->query("combat_exp") < 200000)
	return notify_fail("��ĵĺ���ľ���ȼ�������\n");

        if (random(6) == 0)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm6",1);	
        pet->add("con",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"����"NOR);
	}
       else
        if (random(6) == 1)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm1",1);	
        pet->add("con",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"�����"NOR);
	}
       else
        if (random(6) == 2)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm2",1);	
        pet->add("str",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",RED"������"NOR);
	}
       else
        if (random(6) == 3)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm3",1);	
        pet->add("dex",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIC"������"NOR);
	}
       else
        if (random(6) == 4)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm4",1);	
        pet->add("str",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIB"����"NOR);
	}
       else
        if (random(6) == 5)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm5",1);	
        pet->add("int",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIW"����"NOR);
	}
       else
{
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm1",1);	
        pet->add("con",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"�����"NOR);
}
	pet = present(arg,environment());
	pet->set("ridable",1);
	pet->save();
	gold->add_amount(-cost/2);
	me->add("score",-cost/4);
	command("say ���ˣ���ĺ����Ѿ��ɳ�Ϊ�ڶ���������\n");
	return 1;
}

int do_train2(string arg)
{
	object me,pet,gold;
	int cost;
        me = this_player();
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
	if(!arg) return notify_fail("ӥ����������Ҫʲôѽ����\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("ӥ����������Ҫʲôѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("ӥ���������Ǻ�������İɣ���\n");

//okey we identified the target, now the cost:
	cost = to_int(sqrt(to_float((int)pet->query("combat_exp"))))/3;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost/2)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost/4)
	return notify_fail("��Ľ�����������"+chinese_number(cost)+"�㡣\n");

//to_int(sqrt(to_float((int)pet->query("combat_exp"))))/5;
	pet = present(arg,environment());
        if( pet->query("up1") < 1 )
                return notify_fail("��ĺ��ﻹû�е��ڶ���.\n");

        if( pet->query("up1") >= 2 )
                return notify_fail("��ĺ����Ѿ���������.\n");

	pet = present(arg,environment());
//	if((int)pet->query_skill("puyaogedou") < 200)
//	return notify_fail("��ĵĺ������ҧ�񶷵ȼ�������\n");
	if((int)pet->query("combat_exp") < 500000)
	return notify_fail("��ĵĺ���ľ���ȼ�������\n");

        if (pet->query("title")==HIY"����"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("con",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"������"NOR);
	}
       else
        if (pet->query("title")==HIY"�����"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("con",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"�������"NOR);
	}
       else
        if (pet->query("title")==RED"������"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("str",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",RED"��������"NOR);
	}
       else
        if (pet->query("title")==HIC"������"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("dex",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIC"��������"NOR);
	}
       else
        if (pet->query("title")==HIB"����"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("str",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIB"������"NOR);
	}
       else
        if (pet->query("title")==HIW"����"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("int",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIW"������"NOR);
	}
       else
{
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("con",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"�������"NOR);
}
	pet = present(arg,environment());
	pet->set("ridable",1);
	pet->save();
	gold->add_amount(-cost/2);
	me->add("score",-cost/4);
	command("say ���ˣ���ĺ����Ѿ��ɳ�Ϊ�ռ�������\n");
	return 1;
}
void unconcious()
{
    die();
}
