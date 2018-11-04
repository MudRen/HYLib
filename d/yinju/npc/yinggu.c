inherit NPC;
#include <ansi.h>
string ask_me();
string ask_book();
string ask_yideng();
void create()
{
        set_name("Ӣ��", ({ "ying gu", "gu" }));
        set("nickname", HIR"������" NOR );
        set("gender", "Ů��");
        set("age", 41);
        set("long", 
        "����ɫ������������ʮ�����껪������˼�ǹ��ȣ������ޱ����������\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 35);
        set("dex", 35);
        set("book_count", 1);
        set("max_qi", 11500);
        set("max_jing", 11500);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set_skill("unarmed", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("kurong-changong", 100);     
        set_skill("anying-fuxiang", 300);   
        set_skill("qimen-wuxing",150);     
        set_skill("jinyu-quan", 155);
        set_skill("count",100);            
        set_skill("literate",250);
	set("book_count", 1);
	set("yideng_count", 1);
        map_skill("parry", "duanjia-sword");
        map_skill("cuff", "jinyu-quan");        	
        map_skill("force"  , "kurong-changong");  
        map_skill("dodge"  , "anying-fuxiang");

        prepare_skill("cuff", "jinyu-quan");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
 
             
        set("inquiry", ([
		"һ��" : (:ask_me:),
              "�ϵ�" : (:ask_me:),
                   "�ܲ�ͨ"     : "�����������������",
                "������"     : "����Ϻ��У����ƴȱ���\n",
                "һ�ƴ�ʦ"   : (: ask_yideng :),
                "��������"   : (: ask_book :),
	  ]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
 add_action("do_answer", "answer");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        command("say �����޲�֪������������֮ʣ����������֮ʣ����������֮ʣ�������Ｘ�Σ�");
	return;
}
int do_answer(string arg)
{
      object ob;
      object me=this_player();
          if( arg=="23" )
        { 
          if (query("book_count") < 1)
          {
	   command("say �����������Ѱ��ؼ��͸����������ڴ˴���");
            return 1;
          }
	   add("book_count", -1);
          ob=new("/d/yinju/npc/obj/book");
                 ob->move(me);
          command("say û�뵽���㾹Ȼ����ˡ���Ȼ�������Ҳ����Ե����һ�������顣\n");

         }
         else 
             command("say ���ˣ������ˡ�\n");
        return 1;
}
string ask_me()
{
	 object me,ob;
	 me=this_player();
        ob=new("/d/yinju/npc/obj/bunan");
        ob->move(me);
     return "Ӣ����ü��$N˵����ʮ���ˣ�����ҰѲ��Ҹ������˰ɡ�\n";     
       
}
string ask_book()
{
	mapping fam; 
	object ob;

	if ( (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "����μ�") ||
		(query("book_count") < 1) ) 
		return RANK_D->query_respect(this_player()) + 
		"˵ʲô����ʵ�ڲ����ס�";

	if (this_player()->query_skill("literate",1) < 100)
		return RANK_D->query_respect(this_player()) + 
		"��Ҫ���飿�㻹���������ء�";
	add("book_count", -1);
	ob = new("/d/sdxl/heizhao/npc/lbook4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�������������\n");
	return "�ðɣ��Ȿ���������������û�ȥ�ú����С�\n";
}

string ask_yideng()
{
	mapping fam; 
	object ob;
	
	if (query("yideng_count") < 1)
		return RANK_D->query_respect(this_player()) + 
		"��˵ʲô����һ�ƴ�ʦ���ǿɱ����ҡ�";
	add("yideng_count", -1);
	ob = new("/d/sdxl/heizhao/npc/obj/whiteobj");
	ob->move(this_player());
	ob = new("/d/sdxl/heizhao/npc/obj/yellowobj");
	ob->move(this_player());
	ob = new("/d/sdxl/heizhao/npc/obj/redobj");
	ob->move(this_player());
	return "����������ðɣ��������Ҷ����㣬��Ե���ȥ�����ɡ�\n";
}

      
