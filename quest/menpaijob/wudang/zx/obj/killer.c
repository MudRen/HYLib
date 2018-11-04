#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"����","����","����","����","����",
});

    
string *nm2_jp =({
"��",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))],({"wl renwo"}));
    set("gender", "����" );//�Ա��������Ӧ
        set("long",
"һ����ߴ����������˰̼Ӻ�����������\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
  set("max_qi",500+random(1890));
  set("max_jing",500+random(1890));
  set("max_sen",500+random(1890));
  set("max_neili",500+random(1890));
  set("max_mana",500+random(1890));
  set("eff_neili",500+random(2000));
  set("neili",500+random(2000));
        set("per", 1);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(900000));
	set("bellicosity", 10000);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );

        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        
        set_skill("xue-dao", 150+random(180));
        set_skill("unarmed",150+random(180));
        set_skill("xianglong-zhang",150+random(180));
        set_skill("dodge", 150+random(180));
        set_skill("blade", 150+random(180));
        set_skill("parry", 150+random(180));
        set_skill("dashou-yin", 150+random(180));
        set_skill("shenkong-xing", 150+random(180));
        set_skill("longxiang", 150+random(180));
        set_skill("huntian-qigong", 150+random(180));

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("unarmed","xianglong-zhang");
        map_skill("unarmed","xianglong-zhang");
        prepare_skill("unarmed", "xianglong-zhang");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 100);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

        carry_object("clone/misc/cloth")->wear();
        carry_object("clone/weapon/gangdao")->wield();
}
void init( )
{
        call_out("hunting",300);
}

void hunting()
{
object ob=this_object();
command("say ��������ˣ���!");
destruct(ob);
}


void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (!me) return;
        message_vision(WHT"$N�ҽ�һ�������ض�������\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if(me->query("family/family_name") == "�䵱��" )   {
        message("vision", me->name() + HIG"���ڳɹ��ı������䵱,������300�����150Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",300);
        me->add("potential",150);
        }

        destruct(ob);
        return;
}
