inherit NPC;
int give_qian();
void create()
{
		set_name("ѩɽ����", ({ "shangren", "xueshanshangren","heshang" }) );
		set("title", "�ȱ�Ϊ��");
		set("long","ѩɽ�������ֹ������Ѿ�һ������,�������������������ǩ(qiuqian)���¡�\n");
		set("gender", "����");
		set("age", 80);
		set("attitude", "peaceful");
        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 3);

        set_skill("unarmed", 90);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("literate", 60);
	set("combat_exp",800000);
        set("shen_type",1);
        set("inquiry",(["qiuqian":(:give_qian():)]));	
        setup();
        carry_object("/d/yandang/npc/obj/jiasha")->wear();
		add_money("silver", 56);
}
void init()
{
	::init();
	add_action("do_get","get");
	add_action("do_steal","steal");
}
int do_get(string arg)
{
	object me,obj;
	string from,item;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg, "%s from %s", arg, from)==2)
     {  if (me->query("family/family_name")!="�㵴��")
	{
		if(from=="xiang"||from=="gongde xiang")	{
		command("say ��λʩ���벻Ҫ�Ҷ���");
		return 1;
		}
      }
	return 0;
	}
	return 0;
}
int do_steal(string arg)
{
	object me;
	string from;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg,"%s from %s",arg,from)==2)	{
		if(from=="xiang"||from=="gongde xiang")	{
		command("say �����徲֮�أ�ʩ����Ϊδ��̫�����˰ɣ�");
		return 1;
	}
	return 0;
	}
	return 0;
}


int give_qian()
{
  object me,ob,*inv;
  int count;

  me=this_player();
	inv=all_inventory(me);
	for(count=0;count<sizeof(inv);count++)
	    if(inv[count]->query("id")=="qiantong")
       return notify_fail("����ҡͷ��:ʩ����������,��ͷ�ǰ�,��ͷ�ǰ�.\n");
  else
{
  if( me->over_encumbranced() ) return notify_fail("���Ѿ����ɹ����ˣ�\n");
  clone_object("/d/yandang/obj/qiantong")->move(me);

    command("say �ĳ�����,�Ķ�����,��Ե�춨,�������");  
    message_vision("ѩɽ���˵ݸ�$Nһ�����Ƶ�ǩͲ.\n",me);   
  return 1;}
}
