inherit NPC;
void create()
{
  set_name("�ſ���",({"zhang kangnian","zhang"}));
  set("gender","����");
  set("nickname","��ǰ����");
  set("age",43);
  set("combat_exp",200000);
  set("force",300);
  set("force_factor",24);
  set("chat_chance",3);
  set("chat_msg",({
  "�ſ����:������������,�����̿Ϳ���һ��.\n",
  "�ſ����:�̿͵ĵ����϶���[����ɽ�����ܱ���]������.\n",
  "�ſ����:�𹫹��ڻ�����ǰ���Լ���,���Ǿͷ���.\n",
  }));
  set("max_neili",5500);
        set_skill("force", 80+random(180));
        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 80+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
  setup();
  carry_object("/clone/weapon/gangdao")->wield();
  carry_object("d/city/npc/obj/tiejia")->wear();
  carry_object("d/city/npc/obj/toukui")->wear();
  add_money("silver",30);
 }
#include "shiwei.h"
