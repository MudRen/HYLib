inherit NPC;
int kill_sb();
int have_book=1;

void create()
{
	set_name("������", ({ "baiyi ren", "baiyi", "man" }) );
	set("gender", "����" );
	set("age", 54);
	set("long",
		"һ��ѩ�׵ĳ���,�ڷ���Ʈ��,����䰵��������\n");
	set("combat_exp", 100000);
        set("str", 34);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
	set("attitude", "peaceful");
      set("inquiry",([
       "С÷":(:kill_sb():),
       "xiaomei":(:kill_sb():),
       "����ɽׯ":"�Ӵ���,����,������������!\n",
        ]));	

        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("unarmed",120);
        set_skill("sword",120);
        set_skill("taiji-jian",120);
        map_skill("sword","taiji-jian");
        setup();
        carry_object(__DIR__"obj/xue_cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("coin", 100);
}
int kill_sb()
{
  object me,ob;
  me=this_player();
  if( me->query("cps")>24)
{  if (have_book==0) command("say ��������,������,���´ΰ�,����,Ը���͸�����!\n");
   else
 {  clone_object("/d/yandang/obj/book1")->move(me);
    command("say ����޺�,�Ӵ��������,��������Ҳ����Ե,�Ȿ����͸���ɡ�\n");  
    message_vision("�������͸�$Nһ�����õ���.\n",me);
    have_book=0;   
  return 1;}
  return 1;
 }
  else command("say �����˱��л���,��Ͳ�Ҫ����������!\n");
  return 0;
}

