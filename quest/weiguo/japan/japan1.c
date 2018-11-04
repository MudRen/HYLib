#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"ɽ��","����","����","��","����","����","��֥","��","��Ұ","ɽ��",
"��ľ","�ڲ�","С��","����","����","ǳ��","����","��ĩ","����","���",
"����","����","����",
});

string *id_jp =({
"shanben","guitian","zisan","dadao","songxia","hengtian","dongzhi","houben","chuangye","shankou",
"lingmu","gangcang","xiaodao","jinshang","annai","qiantian","zuoteng","guangmu","dazhu","dachun",
"bozuo","fugang","dongxiang",
});    
    
string *nm2_jp =({
"̫��","����","����","����","����","ʮһ��","ʮ����","��ʮ��","����",
"����","Ӣ��","ұ��","����","����","���","��һ","Ӣ��","��ʯ","�弪",
"һҶ","�ӹ�","����","����","��԰","��ˮ","���","���","Т��","ï",
"��","��","����","����","����","ɽ��","�ζ�",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({id_jp[i]}));
    set("gender", "����" );//�Ա��������Ӧ
//        set_name("��������", ({ "wokou", "japan wokou" }) );
        set("long",
"һ���������ĳ����������˰̼Ӻ����С�ձ���\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIC"��������"NOR);
  set("force_factor",2+random(190));
  set("max_qi",300+random(390));
  set("max_jing",300+random(390));
  set("max_sen",300+random(390));
  set("max_neili",300+random(390));
  set("eff_neili",300+random(390));
  set("neili",300+random(390));
  set("max_mana",300+random(390));
        set("per", 1);
        set("age", 22);
        set("shen", -1000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 100000+random(150000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
		            (: random_move :),
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "�������ܺȵ������˵�,ͳͳ��ɱ��,ɱ���ģ���\n",
                "��������Ц�����������,����,�ûʾ����,����!\n",
                "��������Ц����ɱ�ֆ�!ͳͳ��ɱ��,ɱ���ģ���\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 10+random(100));
        set_skill("blade", 10+random(100));
        set_skill("parry", 10+random(100));
        set_skill("dodge", 10+random(100));
        set_skill("wind-blade", 10+random(300));
        
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
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
{       message_vision(WHT"$N���һ��,�������!!���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 400000)   {
        message("vision", me->name() + "���ڳɹ��ı��������,������450�����250Ǳ�ܡ�\n", me);
        me->add("combat_exp",400);
        me->add("potential",250);
        destruct(ob);
        }
        message("vision", me->name() + "�ɹ��ı����������\n", me);
        me->add("score",2);
        me->add("shen",10);
        destruct(ob);
        return;
}
}
