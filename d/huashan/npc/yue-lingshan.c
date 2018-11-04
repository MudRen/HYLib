// yue-lingshan.c

inherit NPC;

void create()
{
        set_name("����ɺ", ({ "yue lingshan", "yue", "lingshan" }) );
        set("nickname", "Сʦ��");
        set("gender", "Ů��" );
        set("age", 17);
        set("per", 29);
        set("str", 16);
        set("con", 24);
        set("dex", 30);
        set("int", 27);

        set("attitude", "friendly");

        set("max_qi",5800);
        set("max_jing",5500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 80);
        set("combat_exp", 500000);

        set("long",     "����ɺ�ǻ�ɽ����������Ⱥ�Ķ���Ů����\n");

        create_family("��ɽ��", 14, "����");

        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("force", 60);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("literate", 70);

        set_skill("huashan-sword", 150);
        set_skill("yunu-sword", 280);
        set_skill("huashan-ken", 150);
        set_skill("feiyan-huixiang", 150);
set_skill("chongling-jian", 320);
set_skill("zixia-shengong", 150);

        map_skill("sword", "chongling-jian");
        map_skill("parry", "yunu-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.ai" :),
(: perform_action, "parry.wushuang" :),	
				
        }) );
        setup();

        carry_object(__DIR__"obj/green_water_sword")->wield();
        carry_object("/clone/cloth/cloth")->wear();

}

int accept_fight(object me)
{
        command("say СŮ����������Ķ���?");
        return 0;
}
