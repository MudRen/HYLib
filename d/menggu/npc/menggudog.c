// dog.c

inherit NPC;

void create()
{
	set_name("��Ȯ", ({ "dog" }) );
	set("race", "Ұ��");
	set("age",8);
	set("long", "���͵���Ȯ,�����Ϲ��˴��̵ľ�Ȧ��\n");
	
	set("str", 32);
	set("combat_exp",20000);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��","����" }) );
	set("verbs", ({ "bite", "claw","hoof", }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		"��Ȯ��Ǵ�������������Һ��\n",
		"��Ȯ����������ѿ�����¶��������Ȯ����\n",
     }));
	set_temp("apply/attack",30);
	set_temp("apply/armor",30);

	setup();
}
void init()
{
  object ob;
 ::init();
 if (interactive(ob=this_player())&&!is_fighting()) {
 	remove_call_out("greeting");
 	call_out("greeting",1,ob);
     }
}
void greeting(object ob)
{
if (!ob||environment(ob)!=environment()) return;
  if (environment()->query("short")=="���̨Ӫ��")  {	
    message_vision("$N¶����ɫ���,��$n��ȥ.\n",this_object(),ob);
    kill_ob(ob);
    return;
     }
return;
}
