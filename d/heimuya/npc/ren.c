// renying.c

inherit NPC;
string inquiry_linghuchong();

void create()
{
        set_name("��ӯӯ", ({ "ren yingying","ren","ying"}) );
	set("gender", "Ů��" );
	set("age", 20);
	set("shen_type", 1);
	set("combat_exp", 1500000);
	set("per", 30);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set_skill("literate", 180);
	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("unarmed", 160);
	set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("changquan", 160);
         set_skill("sword", 180);
          set_skill("parry", 100);
        set_skill("literate",100);
          set_skill("dodge", 100);
          set_skill("unarmed", 100);
          set_skill("whip", 150);
          set_skill("force", 100);
         set_skill("tmzhang", 180);
        set_skill("staff", 160);
         set_skill("tmjian", 180);
         set_skill("tmdao", 180);
         set_skill("pmshenfa", 180);
          set_skill("strike",200);
         set_skill("blade", 200);
         set_skill("tmdafa", 320);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "unarmed.huashen" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.tmduan" :),                
        }) );
	set("attitude", "friendly");
	set("chat_chance",60);
    	set("chat_msg",({
        "��ӯӯ˵������֪��������������ˣ��Ƿ��ֺ���С������һ��......\n",
        "��ӯӯ˵���������ܰ�������Ӹ�������̫лл����.............\n",
        "��ӯӯ˵����Ҳ��֪����˼�û�����������漱������.......\n",
	   }) );
         set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);      
	   create_family("�������",2,"���� ʥ��");
       set("inquiry",([
	   "�����" : (: inquiry_linghuchong:),
	   ]) );
       set_temp("letter",1);
       setup();
       carry_object("/clone/cloth/female5-cloth")->wear();
       carry_object("/d/heimuya/npc/obj/letter");
	carry_object("/clone/weapon/changjian")->wield();
}

string inquiry_linghuchong()
{
 object me=this_player();
 object obn;

 message_vision("��ӯӯ˵����ȥ���ϻ�ɽһȥ���������ţ������������Ұ�......\n", me );
 if(query_temp("letter")==0)
 {  message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ���
�����ȥѰ���ˣ�Ҳ��֪����ô���ˡ�\n",me);
   return "";
 }
   message_vision("��ӯӯ��˵������λ"+ RANK_D->query_respect(me)+"����������
�ţ���Ҫ���ҵ�����壬�Ͱ��Ž��������������׵ġ�\n" , me);
   obn=new("/d/heimuya/npc/obj/letter");
   obn->move(me);
   set_temp("letter",0);
   
   return ("����ŷ��㽻������塣\n");
}
