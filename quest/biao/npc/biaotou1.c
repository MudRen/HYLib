inherit NPC;
#include "biaotou.h"
void create()
{
        set_name("��ͷ", ({ "biao tou" }));

        set("long", "��ԭ�������ɵ��ӣ�����������ͷ��");
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

        set_skill("force", 50);
        set_skill("hunyuan-yiqi", 50);
        set_skill("dodge", 50);
        set_skill("sword", 50);
        set_skill("shaolin-shenfa", 50);
        set_skill("strike", 50);
        set_skill("sanhua-zhang", 50);
        set_skill("parry", 50);
        set_skill("damo-jian", 50);
        set_skill("buddhism", 50);
        set_skill("literate", 50);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("strike", "sanhua-zhang");
        map_skill("parry", "damo-jian");
        map_skill("sword", "damo-jian");
               setup();  
       add_money("gold", 2);/*      
   set("chat_chance", 15);   
     set("chat_msg", ({
    (: random_move :),
    "��ͷ������: ���������ڵ��¶������������ٷ�ǿ���������ǣ�Ҳ��֪���ټ��ǳ�ʲô�ġ���\n",
        (: random_move :)
  } ) ); 
*/     
        carry_object("/clone/misc/cloth")->wear();        
   	carry_object("/d/city/obj/changjian")->wield();
      }

