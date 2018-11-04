// by dubei
// liumang.c ��å

inherit NPC;
#include <ansi.h>
void create()
{
    set_name("С��å", ({ "xiao liumang", "xiao", "liumang" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���������ֺ��е���å��ר���۸�һЩ���Լ���С���ˡ�\n");
	set("combat_exp", 1000);
	set("shen", -10);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 6);
}
void init()
{
        object ob;

        ::init();
    if (!living(this_object())) return;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        add_action("do_bihua", "bihua");
        }
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
              if ( ob->query("combat_exp",1)<2500)
           message_vision(CYN "$N��ݺݵض�$n˵����ǰ�������Ǽ����ֵܱ�������ݵ��˴����ˣ�������ɵİɣ�
������������ȥ�͸���"HIR"(bihua)"CYN"�Ȼ��Ȼ������Ӯ�ˣ��Ҿ�����һ��·�������ߣ�������������ȥ��\n", this_object(), ob);
        else message_vision("$N���ĵض�$n˵������λ"+RANK_D->query_respect(ob)+"�书��ǿ��ʵ����Ӣ�۳����꣬�����룬�����롣\n", this_object(), ob);
}
int do_bihua()
{
	object me, ob;
	int current_qi,exp;

	me = this_object();
	ob = this_player();
        current_qi = (int)me->query("qi");
        exp = (int)ob->query("combat_exp");
      if (exp >2500) return notify_fail("���������Ұɣ������Һ���Ȼ��أ�\n");
        if (me->is_fighting(ob)) return notify_fail("��ʲ�ἰ����ү�ȴ�������һ�������ѵ�㣡\n");
	command("say �ðɣ���������ҽ�ѵ����ѵ�㡣");
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
        
	while ( ((int)ob->query("qi")*100 / (int)ob->query("max_qi")) > 50) { 
		if ( !present(ob, environment()) ) return 1;
                COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
		if (((int)me->query("qi")*100/current_qi)< 50) {
                   message_vision("$N��ɥ�Ķ�$n˵��������Ȼ���ֲ������������Թ�Ӣ�۳����꣬����С�������ʶ�ˣ�
�Ժ����Ͼ������С�ľ�������ɧ�������ˡ�����˴���������ͷŹ�С�İɡ�˵��
�͹��������İ�$n�õ��������ڽ֡�\n",me, ob);
		   ob->move("/d/xiangyang/eroad1");
           ob->delete("enter_wuguan");
                   tell_room(environment(ob), ob->name() + "�ڼ��д���Ⱥ���������ֵ����˹�����\n", ({ ob }));
		   return 1;
		   }
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                reset_eval_cost();
		}
		say("С��åֺ���������" + ob->name() + "Ʋ��Ʋ�죬˵����������㱾�»�����Ӣ�ۣ������ҹԹԵ�����ȥ�ɣ�\n");
                return 1;
	say("С��å���ͷ��Ķ�" + ob->name() + "˵�����������������Ҫ��Ͷ��֣�����ʲô��\n");
	return 1;
}
void unconcious()
{
    reincarnate();
    set("eff_qi", query("max_qi"));
    set("qi", query("max_qi"));
    set("eff_jing", query("max_jing"));
    set("jing", query("max_jing"));
    set("jingli", query("eff_jingli"));
}

void die()
{
    unconcious();
}
