// zhaixing.c ժ����
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();

string ask_me();
string ask_book();

void create()
{
	set_name("ժ����", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "�����ɴ�ʦ��");
	set("long", 
		"�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�\n"
		"����ʮ���꣬�����������۹���͸��һ˿����֮����\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 5700);
	set("max_jing", 5700);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 30);
	set("combat_exp", 500000);
	set("score", 40000);

	set_skill("force", 170);
	set_skill("huagong-dafa", 150);
	set_skill("throwing", 170);
	set_skill("feixing-shu", 180);
	set_skill("dodge", 170);
	set_skill("zhaixinggong", 200);
	set_skill("strike", 180);
	set_skill("chousui-zhang", 180);
	set_skill("claw", 180);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("parry", 170);
	set_skill("poison", 170);
	set_skill("staff", 170);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"���ĵ�"    : (: ask_me :),
		"�ؼ�"      : (: ask_book :),
		"��ɽ����"  : (: ask_book :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
                "����" : (: ask_job() :)
	]));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("������", 2, "����");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("dan_count") < 1)
		return "�������ˣ�û�����ĵ��ˡ�";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "��Щ���ĵ������õ��˰ɡ�";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ�����ûʲôʣ���ˡ�";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����û�ȥ�úÿ����ɡ�";
}

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

      if( (int)me->query_skill("huagong-dafa",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�����˵���û��ô���ף��㻹�����߾���������");
                return 1;
}
    if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ���Ǳ��̫����.�Ҳ���ʲô�û�!!");
                return 1;
        }

        if (me->query("kill_xingxiu") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "����־ͬ���ϣ��вƴ��һ�𷢡�");
                command("say " + me->query("id") + " ��˵�ڡ�" + quest["short"]             + "�������и�����·������ȥ�ɣ�\n" NOR);
                me->set("kill_xingxiu", 1);
                me->set("quest/quest_type", "��");
                me->set("quest/quest", "����");
                me->set("task_time", time() + 310);
                me->apply_condition("menpai_busy",7);
                ob = new(__DIR__"meinv",1);
                ob->move(quest["place"]);
                me->start_busy(3);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_xingxiu") == 1) {
                command("pk1");
                command("say �㺦�ø���ûץ��,�����ɷ�չ����,����150��POT.");
                me->add("potential",-50);
                me->delete("kill_xingxiu");
                me->apply_condition("menpai_busy",6);
//                call_out("delete", 1);
                return 1;
                }
}



int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(me->query_temp("xxjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say ��������ô���ģ�ɱ�˼������ˣ�");
       return 0;
       }
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }
   if(obj->query("id") == "fu shang" && obj->query_temp("owner/id") != me->query("id")){
       command("consider "+(string)me->query("id"));
       command("say �Ҳ��ǽ���ץ����˵�!");
       return 0;
       }

   if(obj->query("id") == "fu shang" && me->query("kill_xingxiu") == 1)
   {
       command("nod "+(string)me->query("id"));
       command("say �ٺ�.�ɵúã�\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ��ҪǮ��ʲô?");
       return 0;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 7;
if (kar >300) kar=300;

   exp = 620 + kar;
   pot = 520 + random(kar);

   if(obj) destruct(obj);
//   if(ob) destruct(ob);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
                me->apply_condition("guojob2_busy",10);
                me->apply_condition("huang_busy",10);
   message_vision(HIR"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֱ��ŵ��湦��.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ������������ˣ���������\n"
                + chinese_number(exp ) + "��ʵս���飬\n"
                + chinese_number(pot ) + "��Ǳ�ܣ�\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp );
                me->add("potential", pot );
                me->add("score",50);
                me->add("shen",-200);
                me->delete("quest");
                destruct(present("fu shang",ob));
                me->delete("kill_xingxiu");
                me->delete_temp("xxjob2");
   message_vision(HIM"$N˵��Ͱ��������ϵ�Ǯ�ƣ����˳�����Ȼ������˹ؽ��˺����ɽ��......\n"NOR,ob);
   return;      
}