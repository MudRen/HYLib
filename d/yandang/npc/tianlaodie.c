inherit NPC;

void create()
{
	set_name("���ϵ�", ({ "laodie", "tian" }));
	set("gender", "����");
	set("age", 65);
       set("long","���ϵ��������ݽǵ�һ��Բ�������ź���!\n");
       set("inquiry", ([
             "����ɽׯ" : "���ϵ�����������һ��,�ú��̸���ָ��ָ!",
             "�㵴��" : "���ϵ����˷�����˵,û��˵��!",
		]) );
      setup();	
      add_money("silver",2);
      carry_object(__DIR__"obj/hanyangan")->wield();
      carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who,object item)
{	
	if(item->query("id")=="sanqian_silver")
	{
	command("say �Ǻ�,�治����˼,��Զ���㻹������,��ʵҲûʲô,ûʲô!\n");
       command("say ���,����λ"+RANK_D->query_respect(who)+",����«��,����·�Ϻ�!\n");
message_vision("����Ů��$Nһֻ�Ͻ��«.\n",who);
clone_object("/d/yandang/obj/hulu")->move(who);		
return 1;
	}
	command("say ������ʲô��˼,�ٸ�������һ�ס�\n");
	return 0;
}
