#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"��ǹ��"NOR, ({ "pikeman"}));
set("nickname",HIW"��ʥ����"NOR);
if (random(2)==0)
	set("magicgift",5);
else 	set("magicgift",6);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"һλ���µĳ�ǹ����\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",45000000+random(8000000));
        set_skill("spells",450+random(300));
        set_skill("force",450+random(300));
	set_skill("unarmed",450+random(300));
	set_skill("sword",450+random(300));
	set_skill("club",450+random(300));
	set_skill("whip",450+random(300));
	set_skill("throwing",450+random(300));
	set_skill("parry",450+random(300));
      set_skill("magic-unarmed", 450+random(300));
      set_skill("magic-sword", 450+random(300));
      set_skill("magic-light", 450+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-light");
        set("no_get",1);
	set_skill("force",550+random(300));
	set_skill("huntian-qigong",550+random(300));
	map_skill("force", "huntian-qigong");
b=25500+random(6000);
a=27000+random(5000);
d=99+random(60);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);

        set("neili",a);
        set("max_neili",a);
       
    set("age", 15);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

 set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
    (: perform_action, "spells.sunbolt" :),
 }) );
     set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :),
           }) );
   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
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
        message_vision(RED"$N,���ض������������ˡ�\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"�ɹ�����"+ob->query("name")+",������80�����40Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",80);
        me->add("potential",40);
        destruct(ob);
        }

               destruct(ob);
        return;
}


int hit_ob(object me, object ob, int damage)
{
string msg;
        if(random((int)me->query("combat_exp")) > ob->query("combat_exp")/2)   
{
             ob->add("qi",-ob->query("qi")/40);
             ob->add("eff_qi",-ob->query("eff_qi")/40);
           ob->start_busy(2);
           msg = RED"$N"RED"ͻȻ�̳�һǹ!��$n"RED"��������!\n"NOR;
            message_vision(msg, me, ob);
}
}