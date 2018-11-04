// ding.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();


string ask_me();
string ask_du1();
string ask_du2();
string ask_du3();
string ask_du4();
string ask_du5();
void create()
{
	set_name("������", ({ "ding chunqiu", "ding" }));
	set("nickname", "�����Ϲ�");
	set("long", 
		"�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
		"��������������ò���棬�ɷ���ǡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 65);
	set("int", 60);
	set("con", 68);
	set("dex", 68);
	set("per", 68);
	
	set("max_qi", 18000);
	set("max_jing", 18000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("max_neili", 24000);
	set("jiali", 100);
	set("combat_exp", 8500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );
	set("book_count", 1);
	set("zhen_count", 8);
	set("san_count", 3);
	set("wx_count", 6);
	set("xcs_count", 4);
	set("inquiry", ([
		"����" : (: ask_me :),
		"���޶���" : (: ask_me :),
		"������" : (: ask_du1 :),
		"��Ц��ңɢ" : (: ask_du2 :),
		"��ң��Цɢ" : (: ask_du2 :),
		"����ɢ" : (: ask_du3 :),
		"ѩ��˿" : (: ask_du4 :),
		"ͭ��" : (: ask_du5 :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
                "����" : (: ask_job() :)
	]));

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);


	create_family("������", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
      carry_object(__DIR__"chanhunsuo")->wield();
}

void init()
{
        add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100) {
                command("say ����Խ����Խ��׵������Ե׵ġ�");
                return;
        }
        if ((int)me->query("combat_exp") < 10000) {
                command("say �����΢ĩ���������ѧ�����ɵ������");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
         || strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say ����˲������ɷ�����������������㣿");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

// �������ɣ�������أ��������Ž��ޱ�

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����޶��������û�ȥ�ú����С�";
}
string ask_du3()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<50)
		return "��Ķ������δ�����ò������ֶ�����";
	if (this_player()->query_temp("xxi3"))
		return "�Ҹո��������ֶ����ˡ�";

	if (query("wx_count") < 1)
		return "�������ˣ�����ɢ�������ˡ�";
	add("wx_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/wuxing");
	ob->move(this_player());
	this_player()->set_temp("xxi3",1);
	return "�ðɣ�����������������ɢ�ɡ�";
}

string ask_du4()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<50)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("xcs_count") < 1)
		return "�������ˣ�ѩ��˿�������ˡ�";
	if (this_player()->query_temp("xxi4"))
		return "�Ҹո��������ֶ����ˡ�";

	add("xcs_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/xuecan-si");
	ob->move(this_player());
	this_player()->set_temp("xxi4",1);
	return "�ðɣ������������Щѩ��˿�ɡ�";
}
string ask_du5()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_temp("xxi5"))
		return "�Ҹո��������ֶ����ˡ�";

	ob = new("/d/xingxiu/npc/jobobj/tongbo");
	ob->move(this_player());
	this_player()->set_temp("xxi5",1);
	return "�ðɣ�������������ͭ��ɡ����Ǳ��ű���֮��";
}

string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<50)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("zhen_count") < 1)
		return "�������ˣ������붼�����ˡ�";
	if (this_player()->query_temp("xxi1"))
		return "�Ҹո��������ֶ����ˡ�";

	add("zhen_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/blzhen");
	ob->move(this_player());
	this_player()->set_temp("xxi1",1);
	return "�ðɣ������������Щ��ɡ�";
}
string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("san_count") < 1)
		return "�������ˣ�����ûʲôʣ���ˡ�";
	if (this_player()->query_temp("xxi2"))
		return "�Ҹո��������ֶ����ˡ�";

	add("san_count", -1);
	ob = new("/d/xingxiu/npc/jobobj/sanxiao");
	this_player()->set_temp("xxi2",1);
	ob->move(this_player());
	return "�ðɣ������ҩ���û�ȥ�Ƽ����ðɡ�";
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
   exp = 650 + kar;
   pot = 500 + random(kar);

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
