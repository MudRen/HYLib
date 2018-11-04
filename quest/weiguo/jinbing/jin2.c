#include <ansi.h>
inherit NPC;
void create()
{
    set_name("���Уξ", ({ "jinbingxiaowei", "xiaowei" }));
    set("gender", "����" );//�Ա��������Ӧ
        set("long",
"һ��ȫ�����ҵĽ��Уξ��\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIW"���Уξ"NOR);
  set("force_factor",2+random(390));
  set("max_qi",300+random(590));
  set("max_jing",300+random(590));
  set("max_sen",300+random(590));
  set("max_neili",300+random(590));
  set("max_mana",300+random(590));
  set("eff_neili",300+random(390));
  set("neili",300+random(590));
        set("per", 1);
        set("age", 22);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 200000+random(300000));
        set("chat_chance_combat", 50);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.huimaqiang" :),
                (: random_move :),
             }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "���Уξ�ȵ���ɱ���ģ���\n",
                "���УξЦ�������һ��Ҫ��������!\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 50+random(150));
        set_skill("club", 50+random(150));
        set_skill("parry", 50+random(150));
        set_skill("dodge", 50+random(150));
        set_skill("zhong-qiang", 50+random(350));
        
	map_skill("club", "zhong-qiang");
	map_skill("parry", "zhong-qiang");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

        setup();

	carry_object("/d/city/obj/tiejia")->wear();
        carry_object(__DIR__"obj/changqiang")->wield();
	add_money("silver", random(50));
}
void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if( userp(ob[i]) && ob[i]->query("combat_exp") < 80000) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (me)
{
        message_vision(WHT"$N���һ��,�������!!���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 600000)   {
        message("vision", me->name() + "���ڳɹ��ı��������,������600�����300Ǳ�ܡ�\n", me);
        me->add("combat_exp",600);
        me->add("potential",300);
        destruct(ob);
        }
        message("vision", me->name() + "�ɹ��ı����������\n", me);
        me->add("score",2);
        me->add("shen",10);
        destruct(ob);
        return;
}
}
