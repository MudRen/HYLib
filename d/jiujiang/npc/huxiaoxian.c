inherit NPC;

void create()
{
   set_name("��С��",({ "hu xiaoxian","hu"}) );
        set("gender", "Ů��" );
        set("age",21);
   set("long", "�����Ǻ����Ů����С�ɡ���ͷ�������٣�\n"+
               "������ɫ���ˣ�������ɫ����Ŵ�����Ϻ�\n"+
               "ɫ���������ɫխ��ȹ���Ŵ���ͷ�ģ���\n"+
               "����������������̬��\n");       
   set("combat_exp",80000);
   set("str",22);
   set("per",25);
   set_skill("parry",60);
   set_skill("unarmed",60);
   set_skill("dodge",60);
   set_skill("cuff",60);

   set("inquiry",([
    "����":"�����ҵ����������ڳ����أ���Ҳ�ܾ�û�����ˡ�\n",
    "����":"�����С�ӣ���ϧ����һֱû��������\n",
    "������":"����Ӣ����������ϧ���ڼ���û�������ҵ����ˡ�\n",
    "�Ĳ�":"�ҵĶ������ҵ����״��ģ���Ĳ����ҵģ�\n",
    ]));
   
   setup();
   carry_object(__DIR__"obj/pijin")->wear();
   carry_object(__DIR__"obj/changqun")->wear();
   carry_object(__DIR__"obj/male-shoe")->wear();
   carry_object(__DIR__"obj/rushan")->wear();
  
}
void init()
{
  object ob;
  ob=previous_object();
  if(userp(ob)&&!ob->is_fighting()&&living(ob))
   call_out("welcome",0,ob);
}

void welcome(object ob)
{
  if(!ob||!living(ob)||ob->is_fighting())
  return;
  switch(random(5)){
  case 0:command("smile");break;
  case 1:command("nod");break;
  case 2:command("hi");break;
  case 3:command("xixi");break;
  case 4:command("poor");break;}
  return;
}
  