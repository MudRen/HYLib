inherit NPC;
void create()
{
  set_name("����̩",({"aer tai"}));
  set("gender","����");
  set("age",43);
  set("nickname","��ͳ");
  set("combat_exp",800000);
  set("force",700);
  set("max_force",700);
  set("force_factor",40);
        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 80+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
  set("max_neili",500);
        set_skill("force", 80+random(180));

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
  
  set("chat_chance",4);
  set("chat_msg",({
  "����̩��:һ�����Ҽҵ��Ǵ����Ӿ�,�Ҿͺ���.\n",
  "����̩��:��ǰ��Ӫһ��Ҫ������Ӫ����.\n",
  "����̩��:ֻ��̫����ɻ����ټ����ܽ����ʹ�.\n",
  }));
  setup();
  carry_object("/clone/weapon/gangdao")->wield();
  carry_object("d/city/npc/obj/tiejia")->wear();
  carry_object("d/city/npc/obj/toukui")->wear();
  add_money("silver",50);
}
#include "shiwei.h"