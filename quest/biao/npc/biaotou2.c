inherit NPC;
#include "biaotou.h"
void create()
{
        set_name("��ͷ", ({ "biao tou" }));
        set("long", "��ԭ���䵱���ӣ�����������ͷ��");
        set("age", random(20) + 20);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);

        set("max_qi", 300);
        set("eff_qi", 300);
        set("qi", 300);
        set("max_jing", 100);
        set("jing", 100);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);

        set("combat_exp", 50000);
        set("score", 500000);
        set("shen", 0);

        set_skill("force", 100);
        set_skill("taiji-shengong",80);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 60);
        set_skill("cuff", 100);
        set_skill("taiji-quan", 80);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("taiji-jian", 60);
        set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        setup(); 
        add_money("gold",2);        set("chat_chance", 30);   
     set("chat_msg", ({
    (: random_move :),
    "��ͷ������: ���������ڵ��¶������������ٷ�ǿ���������ǣ�Ҳ��֪���ټ��ǳ�ʲô�ġ���\n",
        (: random_move :)
  } ) ); 
        carry_object("/clone/misc/cloth")->wear();        
        carry_object("/clone/weapon/changjian")->wield();

      }



