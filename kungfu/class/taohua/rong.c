// rong.c ����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_chicken();
int ask_zhou();
int ask_husband();
void create()
{
    set_name("����", ({"huang rong", "huang", "rong"}));
    set("title", "�һ�����������Ů");
    set("gender", "Ů��");
    set("age", 18);
        set("long", 
                "���������䣬����ʮ��������ͣ�����ʤѩ�������ޱȣ���ɫ���������ɱ��ӡ�\n"
                "���������磬ȫ����£�ͷ��������һ���������Ȼ���⡣һ��װ��������Ůһ�㡣\n");
        set("gender", "Ů��");
        set("rank_info/rude", "С��Ů");

    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 28);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 8800);
    set("eff_qi", 8800);
    set("max_qi", 8800);
    set("jing", 8000);
    set("eff_jing", 4800);
    set("max_jing", 4000);
    set("neili", 8000);
    set("max_neili", 8000);
    set("jiali", 20);
	
    set("combat_exp", 1800000);
    set("score", 0);
	
    set_skill("force", 160);
    set_skill("bibo-shengong", 280);
    set_skill("unarmed", 180);
    set_skill("xuanfeng-leg", 280);      // ����ɨҶ��
    set_skill("strike", 180);            // �����Ʒ�
    set_skill("luoying-zhang", 280);
    set_skill("dodge", 150);
    set_skill("anying-fuxiang", 270);
    set_skill("parry", 185);
    set_skill("literate",150);           // ����ʶ��
    set_skill("sword", 180);
    set_skill("luoying-shenjian",280);
	
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("strike" , "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
	
    create_family("�һ���", 2, "����");

	set("inquiry", ([
                "name" : "���»��أ����һ�������Ů����",
                "rumors" : "�ҵ��������ﲼ��һ�������󣬱��뾫ͨ���Ե��������ͨ����",
                "����" : "�������Ȼ�е�ɵ�����ģ�����ȴ�����ĵġ�",
                "����" : "��������ʲô����",
                "��ҩʦ" : "�ҵ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
                "����" : "�ҵ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
                "��а" : "�ҵ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
                "�ܲ�ͨ" : "���Ǹ�������ɽ����Ĺ�������һ���Ҵ���������ȥ�棬�������˰����ء�",
                "������" : "�ǵ��������Ե������ŵģ���ͬ�ķ����ʾس�ı仯���ÿ��سΪһ�ԣ����԰�˳���߶Ծ͹����ˡ�",
                "س" : "��Ҳ��֪������û�������ˡ�",
                "�ɷ�" : (: ask_husband :),
                "���" : (: ask_husband :),
		"��ҩʦ" : "����ѽ, ����������? ",
		"����"   : "��ô? �����Ҿ�������Ϣ��? ",
		"���߹�" : "ʦ�������˼Ҿ�ϲ���Խл���! ",
		"�л���" : (: ask_chicken :),
	      	"�ܲ�ͨ": (: ask_zhou :),
	]) );

    setup();
    carry_object(__DIR__"obj/ruanwei")->wear();
    carry_object(__DIR__"obj/shudai")->wear();

}

init()
{
	object ob;
	mapping myfam;
        
	::init();
	add_action("do_kiss", "kiss");
	if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "�һ���") &&
			(!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
	}
}
int ask_husband()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0;

        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id == ob->query("id")) {
                if (nvxu->query("death_count") < ob->query("death_count"))
                        say("���ص���ͷ��Ū���½ǣ�ʲô��Ҳ��˵��");
                else
                        message_vision(CYN"���غ��������ؿ���$N���۹⽿�����ޡ�\n"NOR, ob);
        }
        else {
/*                if (!(user = find_player(id))) {
                        user = new(USER_OB, id);
                        if (!user->restore()) {
                                say("���ص���ͷ��Ū���½ǣ�ʲô��Ҳ��˵��");
                                destruct(user);
                                return 1;
                       }
                        user_load = 1;
                }*/
                if (nvxu->query("death_count") < user->query("death_count"))
                        say("���ص���ͷ��Ū���½ǣ�ʲô��Ҳ��˵��");
                else
                        command("say �ҵ��ɷ����" + nvxu->query("name") + "��");
                if (user_load) destruct(user);
        }
        return 1;
}
int do_kiss ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="rong" )
     return 0;
   
   if ( (string) ob -> query ("gender") == "����" )
      command ("say ����������������"+ ob->query("name") + "Ҫ�����ң�\n") ;
   else
      message_vision("\n���ض�$NЦ�������ý�㲻Ҫ����������������\n", ob);
   return 1 ;
}

void saying(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if ((string)ob->query("gender") == "����")
        message_vision("\n�������־���֮ɫ��������$Nһ�ۣ�˵����������ʲô�ˣ�"
        "�����Ҵ��ҵĹ뷿��\n�ٲ�����ȥ��������ô���㣡��\n", ob);
    else
        message_vision("\n���ؿ��˿�$N��˵�������þ�û���������ˣ�"
        "��֪��λ�������Ҿ�������Ϣ��\n", ob);
}

void attempt_apprentice(object ob)
{
   if ((int)ob->query_temp("marks/�ض�")==1)
   {
      say( "����һ��Ц�⣺����л����������Ŀ���!��\n");
      say( "��������һЦ���Ҳ���ͽ��..��Ҳ�����������������⫼׾��͸���ɣ�\n");
      new("/kungfu/class/taohua/obj/ruanwei")->move(ob);
      tell_object(ob,"���ش���������һ����⫼׵ݸ��㡣\n");
      ob->set_temp("marks/�ض�",2);
   }
   else
    command("say �������ôС����ͽ�ܣ�������Ц��������");
}

string ask_chicken()
{
	if (this_player()->query_temp("marks/��", 1))
		return "���������ô��ô������˵����ꤻ���\n";
	else
	{
		say("�ض�������˵���л������Ǻ��������ز����ҵ�������˺ô�ľ��Ÿ㵽������\n"
			"�����ط�������������ʲô��\n");
		this_player()->set_temp("marks/��", 1);
		return "����Գ�ȥ�ˡ�\n";
	}
}

int ask_zhou()
{
	object me = this_player();
	if (me->query_temp("jiuyin/huang")) {
		command("say �������Ǳ��������ڵ��ϣ���֪��Ϊʲô��");
		command("say �����춼�����ͷ��������������Ҫ�Һú���Щ����������");
		command("angry");
		command("say �����ɣ��������ȥ�ɺã�");
		if (!present("fan he", me)) {
			new(__DIR__"obj/fanhe")->move(this_object());
			command("give fan he to " + me->query("id"));
		}
		me->delete_temp("jiuyin/huang");
		return 1;
	}
	return 0;
}
