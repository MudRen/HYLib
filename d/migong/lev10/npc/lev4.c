// migong lev10  һ��ָ �����

#include <ansi.h>

inherit NPC;


string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",

"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "man" }));
 
set("title", YEL"а������"NOR);
   set("gender", "����" );
 set("long",
"�޶����Ľ������ࡣ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",2500+random(2000));
  set("max_jing",2500+random(2000));
  set("max_sen",2500+random(2000));
  set("max_neili",2500+random(2000));
  set("max_mana",2500+random(2000));
  set("eff_neili",2500+random(2000));
  set("neili",2500+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 4000000+random(2000000));
                 set_skill("finger", 360+random(60));

set_skill("strike", 360+random(60));

set_skill("kurong-changong", 360+random(60));

set_skill("force", 360+random(60));
set_skill("yiyang-zhi", 360+random(60));

set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("haotian-zhang", 360+random(60));

set_skill("tiannan-step", 360+random(60));

  
        map_skill("finger", "yiyang-zhi");
  
      map_skill("parry", "yiyang-zhi");

 map_skill("force", "kurong-changong");

 map_skill("dodge", "tiannan-step");
 
map_skill("strike"  , "haotian-zhang");
prepare_skill("strike", "haotian-zhang");
prepare_skill("finger", "yiyang-zhi");
set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
 
      (: perform_action, "finger.sandie" :),
	
        (: exert_function, "recover" :),
    (: exert_function, "ku" :),
     (: exert_function, "rong" :),
    (: exert_function, "powerup" :),
    (: perform_action, "finger.sandie" :),
	
 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
 
          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);

      set("chat_chance", 20);
        set("chat_msg", ({
		(: command("get silver") :),
		(: command("get coin") :),
                (: random_move :),
           }) );   

        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
add_money("silver", random(10));


}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
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
        if (!me) return;
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 6000000)   {
        message("vision", me->name() + "Ϊ��������,������300�����100Ǳ�ܡ�\n", me);
        me->add("combat_exp",300);
        me->add("potential",100);
        destruct(ob);
        }
        destruct(ob);
        return;
}