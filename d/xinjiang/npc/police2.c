 // Copyright (c) 1998 Apstone, Inc.
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "eagle gulina", "gulina" }) );
        set("long", "tt");
        set("nickname",HIY "�ϳ��ӥ"NOR);
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("vendetta_mark","pker");
        set("reward_npc", 1);
        set("difficulty", 35);
        set("str", 60);
        set("dex", 60);
        set("gender", "Ů��");
        set("cor", 26);
        set("max_qi",100000);
        set("max_jing",100000);
                set("max_neili", 25000);
        set("neili", 25000);
        set("max_sen",100000);
        set("max_mana",1000);
        set("mana",1000);
        set("cps", 25);
        set("agi", 40);
        set("combat_exp", 6000000+random(4000000));
        set("chat_chance", 30);
        set("chat_msg", ({
        (: random_move :)
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
                "��ͻȻ�о�����������ζ������\n",
        }) );
        set_skill("unarmed", 370+random(100));
        set_skill("parry", 370+random(100));
        set_skill("dodge", 370+random(100));

        set_skill("spells",100);
	set_skill("sword", 300);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",350);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");

        set_temp("apply/attack", 270);
        set_temp("apply/dodge", 270);
        set_temp("apply/armor", 370);
        set_temp("apply/damage", 330+random(200));


        setup();
        carry_object("/clone/master/obj/bsword")->wield();
        carry_object(__DIR__"obj/skirt")->wear();
} 
void init()
{
        object ob;
        ::init();
        if(userp(ob = this_player()) && ob->query("vendetta/pker") && !ob->query("disable_type"))
        {
                message_vision( HIW "$N˫��һ�ۣ��γ�һ������ĺ�������$n������\n
����ĺ�����Χ��$n��ȫ����$n���۳ɱ��飡\n"NOR, this_object(), ob);
ob->set("qi",100);
ob->set("eff_qi",100);
ob->set("neili",100);
ob->set("jing",100);
ob->start_busy(10);
//              ob->delete("max_force");
                //ob->set_temp("disable_inputs",1);
                //ob->set("disable_type",HIW "<������>"NOR);
                //ob->set_temp("is_unconcious",1);
                //seteuid(ROOT_UID);
                //ob->start_call_out( (: call_other, __FILE__, "remove_frozen",ob:), 
                //random(20)+20);
                //ob->start_call_out((:call_other,__FILE__,"remove_frozen", ob, 1:), random(20)+20);
                
                ob->kill_ob(this_object());
                kill_ob(ob);
        }
} 
void remove_frozen(object me)
{
   me->delete("disable_type");
   me->delete_temp("disable_inputs");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n"NOR, me);
}        
