inherit NPC;
void create()
{
   set_name("��",({"rui dong"}));
   set("gender","����");
   set("age",36);
   set("dex",100);
   set("nickname","�������ܹ�");
	set("shen_type",-1);
   set("combat_exp",1000000);
set("jing",30000);
set("eff_jing",30000);
set("max_jing",30000);
set("kar",200);
   set("force",600);
   set("max_force",600);
   set("force_factor",20);
     set("max_neili",20000);
        set_skill("force", 480+random(180));

        set_skill("unarmed", 280+random(180));
        set_skill("blade", 280+random(180));
        set_skill("parry", 280+random(180));
        set_skill("dodge", 280+random(180));
        set_skill("kuang-blade", 280+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
   set("inquiry",([
   "̫��":"��ҪΪ̫��������,Ҳ������ϧ.\n",
   "ΤС��":"��Ҳ��������С��.\n",
   ]));
  set("chat_chance",15);
  set("chat_msg",({
  "�𶰵�:�ⲿ[��ʮ���¾�]��̫��Ը�Ҫ��,�ɲ��ܶ���.\n",
  "�𶰵�:�������ִ̿�,��˵���˺ü�������.\n",
  "�𶰵�:���ϴ�,����̫���?�ǵ�Ȼ��̫�����.\n",
                (: random_move :),
  }));
   
   setup();
   add_money("silver",10);
  carry_object("/clone/weapon/gangdao")->wield();
  carry_object("d/city/npc/obj/tiejia")->wear();
  carry_object("d/city/npc/obj/toukui")->wear();
  carry_object("/d/city2/obj/book14_4");
}
#include "shiwei.h"