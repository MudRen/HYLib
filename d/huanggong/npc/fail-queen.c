#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY "��̫��" NOR, ({ "empress","queen"}));
        set("shen_type", 0);
        set("age",43);
        set("gender", "Ů��");
        set("per",24);
        set("long",
                "�����ð������֣�Ҳ�������겻�����⣬����������ɫ�Եúܲ԰ס�\n");
        set("max_neili",5000);
        set("max_jingli",4000);
        set("jingli",4000);
        set_skill("unarmed",200);
        set_skill("parry",200);
        set_skill("sword",200);
        set_skill("force",200);
        set_skill("throwing",200);
        set_skill("taoism",200);
        set_skill("literate",200);
        set("chat_chance", 5);
        set("chat_msg", ({
"��̫��˵����С����֪������̫���ˣ�����ס�����죬��˯Ҳ˯���ţ�\n",
        }) );

        set("combat_exp", 800000);
        set("attitude", "friendly");
        set("inquiry", ([
                "�ݺ�" : "��ʲô��˼......��\n",
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}

int accept_object(object me, object obj)
{
	object pai;
        if( (string) obj->query("name") == "С����"
        || obj->query("id") =="xiao guizi")
	{
        message_vision("$N��$n���˵�ͷ��\n",this_object(),me);
        command("heihei");
	command("say ���úã���ȥ�ҵ��Ĳ���\n");
	command("say �Ȿ42�¾����ͽ����㱣���ˣ�\n");
	pai = new("/d/city2/obj/book14_2");
	if(pai)
	pai->move(me);
        message_vision("$N�ó�һ��42�¾�����$n��\n",this_object(),me);
        call_out("destroying", 0, obj,me);                       
	return 1;	
	}
else       return 0;
}

void destroying(object obj, object ob, object me)
{   

   if(obj) destruct(obj);
}
