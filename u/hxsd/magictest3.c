//Npc �ȹ���ʮ��
//diabio(����)2003.3.1
#include <ansi.h>
inherit NPC;
int ask_tianxiang();
inherit F_MASTER;
void create()
{
        set_name("ħ������Ա", ({ "ice test", "magictest" }));
        set("long", "������ħ������Ա��ʦ���� \n");
        set("title", HIC"��ϵħ��"HIW"����Ա"NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude","peaceful");
        set("zhuanbest",1);
        set("str", 90);
        set("dex", 190);
        set("con", 90);
        set("int", 90);
        set("per", 20);
        set("per",23);
        set("tianyu_1",1);
        set("max_qi", 600000);
        set("max_jing", 100000);
        set("max_neili", 5000000);
        set("max_jing",1000);
              set("neili",5000000);
        set("qi",600000);
        set("jing",10000);
        set("jing",10000);
        set("combat_exp", 19000000);
        set_skill("cuff",600);
        set_skill("dodge",600);
        set_skill("unarmed",600);
        set_skill("parry",600);
        set_skill("blade",600);
         set_skill("feitian-yujianliu",600);
         set_skill("shayi-xinfa",800);
        set_skill("force",600);
        set_skill("sword",600);
        set_skill("aikido",600);
        set_skill("spells",600);
        set_skill("wuxing-dun",600);
        set_skill("magic-unarmed",600);
set_skill("magic-dark",800);
set_skill("magic-earth",800);
set_skill("magic-ice",800);
set_skill("magic-water",800);
        set_skill("magic-fire",800);
        set_skill("magic-sword",600);
        set_skill("huoxinliu-jianfa",600);
        set_skill("xuanhualiu-quanfa",600);
        set_skill("literate",350);
        map_skill("cuff", "xuanhualiu-quanfa");
        map_skill("unarmed", "magic-unarmed");
        map_skill("dodge", "wuxing-dun");
        map_skill("sword", "magic-sword");
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
        map_skill("parry", "magic-unarmed");
        map_skill("spells", "magic-ice");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.invisibility" :),
               (: perform_action, "spells.lightningball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.implosion" :),
               (: perform_action, "spells.lightningbolt" :),
               (: perform_action, "spells.stun" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.holylightning" :),                                                            
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say( "ħ������ԱЦ��˵����ֻ����������书��\n");
        command("hehe");

}

void die()
{
        unconcious();
}