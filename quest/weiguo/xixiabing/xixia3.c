#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"����",
});

    
string *nm2_jp =({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))],({"yuanshuai"}));
    set("gender", "����" );//�Ա��������Ӧ
//        set_name("��������", ({ "wokou", "japan wokou" }) );
        set("long",
"һ����ߴ����������˰̼Ӻ���������ˡ�\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIR"����Ԫʦ"NOR);
  set("force_factor",2+random(1390));
  set("max_qi",1300+random(1690));
  set("max_jing",1300+random(1890));
  set("max_sen",300+random(1890));
  set("max_neili",1300+random(1890));
  set("max_mana",1300+random(1890));
  set("eff_neili",1300+random(1390));
  set("neili",300+random(1390));
        set("per", 1);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(8000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
                (: random_move :),
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "����Ԫʦ�ȵ���ɱ���ģ���\n",
                "����ԪʦЦ�������һ��Ҫ��������!\n",
                (: random_move :),
        }) );
        
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 280+random(180));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
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
        message_vision(WHT"$N���һ��,��������!!���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 1800000)   {
        message("vision", me->name() + "���ڳɹ��ı���Ϊ��,������800�����400Ǳ�ܡ�\n", me);
        me->add("combat_exp",800);
        me->add("potential",400);
        me->add("score",50);
        destruct(ob);
        }
        message("vision", me->name() + "�ɹ��ı����������\n", me);
        me->add("score",2);
        me->add("shen",10);
        destruct(ob);
        return;
}
}
