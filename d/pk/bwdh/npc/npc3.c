// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// ����Ⱥ
// ��npc�ϵ�xunshan���ò�����
// ����lywin����2000/6/11

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_xunshan();
string ask_me();
string ask_feng();

void create()
{
        set_name("С����Ⱥ", ({ "yue buqun", "yue" }) );
        set("title", "��ɽ������");
        set("nickname", "���ӽ�");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "����Ⱥ����ִ�ƻ�ɽ�ɣ��˵���������һ��һ�ĸ��֡�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 14400);
        set("max_neili", 14400);
        set("jiali", 50);
        set("max_qi",8200);
        set("max_jing",5200);

        set("combat_exp", 1400000);
        set("shen", -200000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.feilong" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
	    "������" : "�����ҷ��ˡ�\n",
	    "�����" : "������Ů����\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",          
	    "˼����" : "���Ǳ��ɵ�������˼��֮����\n", 
        ]) );

        set_skill("unarmed", 80);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 200);
        set_skill("zixia-shengong", 200);
        set_skill("huashan-ken", 200);
        set_skill("feiyan-huixiang", 200);
        set_skill("pixie-sword",80);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
        carry_object(__DIR__"obj/badan");
}
