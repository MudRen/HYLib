#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#define __THD__ "/d/taohua/"

void consider();
string ask_me();
int ask_marry();
int ask_test1();
int ask_test2();
int ask_test3();
int ask_nvxu();

int ask_zhou();

void create()
{
    set_name("��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "�һ�����");
    set("nickname", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
        set("long", 
                "�������һ����ĵ���������������������ɫ�Ķ�а��ҩʦ��\n"
                "����һ����ɫ���ۣ�������б����һֻ���\n"
                "��������񳣬������ˬ���������٣�տȻ����\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 60);
    set("per", 60);

    set("chat_chance", 1);
    set("chat_msg", ({
        "��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
        "��ҩʦ��ͷ��˼����Ȼ���\n",
    }));
/*    set("inquiry", ([
        "����"     : "���ֱ����Ů���Ĺ����� \n",
        "�����澭" : "������ܰ���ȡ���澭�ϲᣬ��һ������л�㡣\n",
    ]));*/

    set("qi", 29000);
    set("max_qi", 29000);
    set("jing", 18000);
    set("max_jing", 18000);
    set("neili", 53500);
    set("max_neili", 53500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 9000000);
    set("score", 0);
	 
    set_skill("leg", 380);             // �����ڹ�
    set_skill("force", 280);             // �����ڹ�
    set_skill("bibo-shengong", 380);     // �̲���
    set_skill("claw", 200);              // ����צ��
    set_skill("hand", 320);              // �����ַ�
    set_skill("finger", 320);            // ����ָ��
    set_skill("tanzhi-shentong", 380);   // ��ָ��ͨ
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("strike", 280);            // ����ȭ��
    set_skill("luoying-zhang", 380);     // ��Ӣ����
    set_skill("xuanfeng-leg", 380);      // ����ɨҶ��
    set_skill("dodge", 280);             // ��������
    set_skill("anying-fuxiang", 380);    // ��Ӱ����
    set_skill("parry", 200);             // �����м�
    set_skill("sword", 320);             // ��������
    set_skill("luoying-shenjian", 380);  // ��Ӣ��
    set_skill("yuxiao-jian", 380);       // ���｣��
    set_skill("lanhua-shou", 380);       // ������Ѩ��
    set_skill("qimen-wuxing",380);       // ��������
    set_skill("count",380);              // ��������
    set_skill("literate",380);           // ����ʶ��
	  set_skill("chixin-jian", 380);             // �����ڹ�
    set_skill("canglang-bian", 380);             // �����ڹ�
    set_skill("whip", 380);             // �����ڹ�
    map_skill("strike"  , "luoying-zhang");
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("whip"   , "canglang-bian");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "chixin-jian");
    map_skill("parry"  , "luoying-zhang");    	

if (random(3)==0)
{
    	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-leg");
}
else
{
	prepare_skill("finger", "tanzhi-shentong");
	prepare_skill("hand", "lanhua-shou");	
}
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "qimenzhen" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.wuying" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
		(: command("unwield yuxiao") :),
		(: command("wield yuxiao") :),
		(: command("unwield bian") :),
(: command("wield bian") :),
(: perform_action, "finger.ding" :), 
	(: perform_action, "finger.zhuan" :), 
(: perform_action, "sword.muyu" :),                
	(: perform_action, "sword.nosword" :),                
		(: perform_action, "sword.trhy" :),                
		(: perform_action, "whip.duoming" :),                
		(: perform_action, "whip.lang" :),                
		(: perform_action, "whip.tlyj" :),                
		(: perform_action, "whip.yljx" :),                									
 
        }));
    set("inquiry", ([
                "name": "�ѵ�����¾�û��֪���Ҷ�а��ҩʦ����������",
                "rumors": "��˵ȫ����ǰ�ţ�����ڵ������ܲ�ͨ���ߣ�",
                "��а": "�Ƕ��ǽ������ǰ�����������µļһ������Ĵºš�",
                "����": "��ǰ��������ŷ������ֻ����󡣬���˻�ˣ�������⣬ûʲô�湦��",
                "ŷ����": "��ֻ����󡣬���˻�ˣ�������⣬ûʲô�湦��",
                "�ϵ�": "��ǰ���ϵ��Ǵ������ү�����ˣ����ڳ��������У��Ľ�һ������",
                "һ��": "��ǰ�Ǵ������ү�����ˣ����ڳ��������У��Ľ�һ������",
                "������": "��ǰ�Ǵ������ү�����ڳ��������У��Ľ�һ������",
                "��ؤ": "��ǰ�ı�ؤ�Ǻ��߹��Ǹ��Ͻл������ֽ�ʲôʮ���Ƶ���ʹ�á�",
                "���߹�": "�Ǹ��Ͻл���ؤ����������ֽ�ʲôʮ���Ƶ���ʹ�á�",
                "����ͨ": "��ǰ������ͨ��ȫ��̵ĳ���ʿ��������Ҫ�����Ϸ�һʱʧ�֣����ֵ�һ�ĳƺ�Ҳ���ᱻ�����ߡ�",
                "������": "��ȫ��̵ĳ���ʿ��Ҫ�����Ϸ�һʱʧ�֣����ֵ�һ�ĳƺ�Ҳ���ᱻ�����ߡ�",
                "�ܲ�ͨ": "�����ɵ�ϣ�����ƭ�˶���֪������������������ٺٺ�....",
                "����ͯ": "�����ɵ�ϣ�����ƭ�˶���֪������������������ٺٺ�....",
                "����": "������С�Ͷ���������������������Ƥ���ԣ���Ҳû�취�ˡ�",
                "�ض�": "������С�Ͷ���������������������Ƥ���ԣ���Ҳû�취�ˡ�",
                "����": "���������ɵŮ���ˡ�",
                "Ů��": (: ask_nvxu :),
                "�˷�": "���ҵ��ĵ��ӣ�����ס�ڹ���ׯ��",
                "½�˷�": "���ҵ��ĵ��ӣ�����ס�ڹ���ׯ��",
                "��ҩʦ": "�����Ϸ��ҡ���ô������������������",
                "�Ź�": "�Ź�֮�壬������ꡣ����Ϊ�磬����Ϊ�㣻�������ߣ�������һ������м䡣",
                "����": "Ǭ�����������Σ������飬�������������ۣ��޸��룻����ȱ�����¶ϡ�",
                "����": "����ˮ��ˮ��ľ��ľ���𣬻������������𡣽��ľ��ľ����������ˮ��ˮ�˻𣬻�˽�",
                "�׾�": "��һ�����������ʮ���Ե����飬һ�����ѵÿ�����",
                "����": "��һ�����������ʮ���Ե����飬һ�����ѵÿ�����",
                "�����澭": "����������ʲô����",
                "����": "�Ϸ��ҶԺ��о����Ʋ��ߣ�",
                "���": (: ask_marry :),
                "��һ��": (: ask_test1 :),
                "test1": (: ask_test1 :),
                "�ڶ���": (: ask_test2 :),
                "test2": (: ask_test2 :),
                "������": (: ask_test3 :),
                "test3": (: ask_test3 :),
        "�ؼ�" : (: ask_me :),
        "����ɨҶ�ȷ�" : (: ask_me :),
      	"�ܲ�ͨ": (: ask_zhou :),
    ]));


    create_family("�һ���", 1, "����");
    setup();
	
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
if (random(3)==0)
{	
	 carry_object(__DIR__"obj/yuxiao")->wield();
carry_object(__DIR__"obj/hlbian");
}
else
{
carry_object(__DIR__"obj/hlbian")->wield();
carry_object(__DIR__"obj/yuxiao");
}
    carry_object(__DIR__"obj/bupao")->wear();
//    carry_object("clone/book/jiuyin2");
    
}

void attempt_apprentice(object ob)
{
        string old_name, new_name;
    if (ob->query_int() < 30) {
        command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�");
		return;
    }
        if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
                command("say �㲻�в�Ů����ʲô�����������");
                return;
        }
        if (ob->query("shen") <= -200000) {
                command("say ����ƽ�����������ˣ����������޶�����аħ���������һ���ߣ�");
                return;
        }
        if (ob->query("shen") >= 200000) {
                command("say ����ƽ�����������ˣ������������������Ĺ�������֮ͽ������һ���ߣ�");
                return;
        }
        if (ob->query_int() < 28) {
                command("say �����⸱ģ����������ɵŮ���������������Ϊʦ��");
                return;
        }
        if (!ob->query_skill("literate")) {
                command("say �������äҲ����ѧ������ȥѧ���Ļ��ɡ�");
                return;
        }


        if (ob->query("class") == "bonze") {
                if (ob->query("family/family_name") == "������")
                        command("say �������������书�����֣����������С���ɲ������㡣");
                else
                        command("say �Ҷ�а��������У�������ͷ����������������á�����һ�𶼲��ա�");
                return;
        }

    if ((int)ob->query_skill("bibo-shengong",1) < 50 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
		return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say ���һ��������������������������ֳ�������򽻵�������ذɣ�");
		return;
	}

    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
                command("chat ����������������");
                command("chat �벻���Ҷ�а�������֮�󣬻��ܵô��������ʣ����ǿ�ϲ�ɺء�");
                command("recruit " + ob->query("id"));
                old_name = ob->query("name");
                new_name = old_name[0..3] + "��";
                ob->set("name", new_name);
                say(old_name + "�����ҩʦ���£�λ�ж������ӡ��硱�ֱ�������Ϊ" + new_name + "��\n");

}

int recognize_apprentice(object ob)
{
	mapping myfam;
       	myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "�һ���") return 1 ;
	if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("��ҩʦ���˿�$N��˵��������������˭Ҳ��Ƿ˭,\n"
                          "�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
	if (!(int)ob->query_temp("tmark/��"))
		return 0; 
	ob->add_temp("tmark/��", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jiuyin zhenjing1" ) {
 		if (!(int)who->query_temp("tmark/��")) who->set_temp("tmark/��", 0);
		message_vision("��ҩʦ���˿�$N�������ؼ������˵�ͷ��˵����\n"
                               "�ѵ��㽫�澭�ͻء������ҵĶ����Ҿ������ˡ�\n"
                               "��Ϊ����,����Դ�������ѧ�㹦��\n", who);
		who->add_temp("tmark/��", 120);
		return 1;
	}
	return 0;
}
string ask_me()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(this_player()) + 
		"���ҵ��ӣ���֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�����ɨҶ�ȷ�����\n");
	return "�ðɣ��Ȿ������ɨҶ�ȷ������û�ȥ�ú����С�";
}
//void die()
//{
//message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"���˾����澭�¾�����\n"NOR, users());
//	::die();
//}
int ask_zhou()
{
	command("say ��һ��о����澭���Ͼ�������Ҳ���Ͻ�������");
	command("sneer");
	command("say �ҽ������ڵ��ϣ������ܳŵ���ʱ��");
	this_player()->set_temp("jiuyin/huang", 1);
	return 1;
}
void init()
{
        object ob = this_player();

        add_action("do_answer","answer");
        add_action("do_answer","huida");
        ::init();

}


int ask_marry()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0, user_exist = 1;

        if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
                command("sneer " + ob->query("id"));
                command("say ��Ҳ��Ȣ���ţ��±��Ӱɣ�");
                return 1;
        }
        if (ob->query("gender") == "Ů��") {
                command("say �㵱��Ů����ͬ�������������");
                return 1;
        }
        if (ob->query("class") == "bonze") {
                command("sneer " + ob->query("id"));
                command("say ����Ҳ���˷��ģ���Ȣ���ţ��Ȼ�����˵�ɣ�");
                return 1;
        }
        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id) {
                if (id == ob->query("id") && nvxu->query("death_count") == ob->query("death_count")) {
                        say(CYN"��ҩʦЦ����" + RANK_D->query_rude(ob) + "�����������������\n"NOR);
                        return 1;
                }
                if (!(user = find_player(id))) {
                        user = new(USER_OB, id);
                        user->set_name("", ({ id }));
                        if (!user->restore()) {
                                destruct(user);
                                user_exist = 0;
                        }
                        else user_load = 1;
                }
/*                if (user_exist && nvxu->query("death_count") == user->query("death_count")) {
                        command("say СŮ�Ѿ������" + nvxu->query("name") + "�ˡ�");
                        if (user_load) destruct(user);
                        return 1;
                }*/
                if (user_load) destruct(user);
        }
        if (ob->query("marry")) {
                command("sneer " + ob->query("id"));
                command("say �㲻���Ѿ�Ȣ��������������޸��ı��ҵ��ˣ��������£��ݹ��Ϸ�����");
                return 1;
        }
        if ((int)ob->query("shen") <= -200000) {
                command("say ����ƽ�����������ˣ����������޶�����аħ���������һ���ߣ�");
                return 1;
        }
        if ((int)ob->query("shen") >= 200000) {
                command("say ����ƽ�����������ˣ������������������Ĺ�������֮ͽ������һ���ߣ�");
                return 1;
        }
        if (ob->query("age") > 49) {
                command("sneer " + ob->query("id"));
                command("say ����ô������ͷҲ������Ů�����ɴ�������Ů�����ˡ�\n");
                return 1;
        }
        if (ob->query("class") == "taoist") {
       command("say �Ҷ�а�������ʿ��������ʿ��������");
                return 1;
        }

        if (ob->query("age") < 20) {
                command("say �㻹С���ȳ����������ɡ�\n");
                command("pat " + ob->query("id"));
                return 1;
        }
        command("say �ðɣ�������Ҫ���������⿼���㡣");
        command("say ��һ�����书���ڶ��������ɣ���������Ĭд��");
        command("say �������󶼲�������У�");
        command("say Ҫ��׼�����˾�������һ�ذɣ�");
        ob->set_temp("thd_marry", 1);
        return 1;
}

int ask_test1()
{
        object ob=this_player();
        object me=this_object();
        object obj;

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") > 1) {
                command("say �Ѿ�������ػ�������ʲô��");
                return 1; 
        }
        
        set("combat_exp", 2000000);
        set("jiali", 100);
        if (present("yuxiao",me))
                command("unwield yuxiao");
        prepare_skill("strike");
        prepare_skill("leg");
        prepare_skill("hand");
        prepare_skill("finger");
        prepare_skill("sword");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        say("\n��ҩʦ�ȵ�����һ������Ӣ���ƣ�С�Ľ����ˣ�\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
          if (!present("yuxiao",me))
        if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
        else
                command("wield yuxiao");
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 2500000);
                set("jiali", 120);
                return 1;
        }
        prepare_skill("strike");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        say("\n��ҩʦ�ȵ����ڶ��������｣����С�Ľ����ˣ�\n");
        if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                command("wield yuxiao");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 2600000);
                set("jiali", 200);
                return 1;
        }
        if (present("yuxiao",me))
                command("unwield yuxiao");
        prepare_skill("strike");
        me->reset_action();
        prepare_skill("hand", "lanhua-shou");
        say("\n��ҩʦ�ȵ�����������������Ѩ�֣�С�Ľ����ˣ�\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
                else
                        command("wield yuxiao");
                prepare_skill("finger");
                me->reset_action();
                prepare_skill("strike", "luoying-zhang");
                prepare_skill("leg", "xuanfeng-leg");
                set("combat_exp", 3000000);
                set("jiali", 200);
                return 1;
        }
        prepare_skill("hand");
        me->reset_action();
        prepare_skill("finger", "tanzhi-shentong");
        say("\n��ҩʦ�ȵ����������ǵ�ָ��ͨ��С�Ľ����ˣ�\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present("yuxiao",me))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
        else
                command("wield yuxiao");
        prepare_skill("finger");
        me->reset_action();
        prepare_skill("strike", "luoying-zhang");
        prepare_skill("leg", "xuanfeng-leg");
        set("combat_exp", 3200000);
        set("jiali", 200);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
                return 1;
        }

command("wield yuxiao");
        write("��ҩʦ˵�����ðɣ����һ�ؾ�������ˡ�\n");
        write("��ҩʦ˵������Ҫ��׼�����˾������ڶ��ذɣ�\n");
        tell_room(environment(ob), "��ҩʦ��" + ob->name() + "˵�����ðɣ����һ�ؾ�������ˡ�\n", ({ob}));
        ob->set_temp("thd_marry", 2);
        return 1;
}

int ask_test2()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 2) {
                say("��ҩʦ�ȵ�����ô��������ô����\n");
                return 1; 
        }
        if (ob->query_temp("thd_marry") > 2) {
                command("say �Ѿ�������ػ�������ʲô��");
                return 1; 
        }
        
        command("say ��ν���������˹��̽����⣬����һ����ʲô��");
        return 1;
}

int ask_test3()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 3) {
                say("��ҩʦ�ȵ�����ô��������ô����\n");
                return 1; 
        }
        command("say �����澭�Ե�����֮����������������㣬�ǹ�....���������������ʲô��");
        return 1;
}

int ask_nvxu()
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
                        command("say СŮ������Ȼ���ֹ��С�");
                else
                        say(CYN"��ҩʦЦ����" + RANK_D->query_rude(ob) + "�����������������\n"NOR);
        }
        else {
                if (id) {
                        if (!(user = find_player(id))) {
                                user = new(USER_OB, id);
                                user->set_name("", ({ id }));
                                if (!user->restore()) {
                                        command("say СŮ������Ȼ���ֹ��С�");
                                        destruct(user);
                                        return 1;
                                }
                                user_load = 1;
                        }
                }
                if (!id || nvxu->query("death_count") < user->query("death_count"))
                        command("say СŮ������Ȼ���ֹ��С�");
                else
                        command("say ���Ѱ�СŮ�����" + nvxu->query("name") + "Ϊ���ˡ�");
                if (user_load) destruct(user);
        }
        return 1;
}

int do_answer(string arg)
{
        object ob = this_player();
        object nvxu;
        object obj;
    int payed;

        if (ob->query_temp("thd_marry") == 2) {
                tell_room(environment(ob), ob->name() + "�ڻ�ҩʦ�Ķ���С���ֹ���һ�䡣\n", ({ob}));
                if (arg == "��") {
                        if (!present("yuxiao",this_object()))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
command("wield yuxiao");
                        command("say ��С�ӣ������������ҵġ��̺�����������\n");
                        write("��ҩʦ�ӻ���ȡ��һ֧����ŵ���ߴ�����������·������֮�У�������ӿ�������ƺ�Ҫ������û��\n");
                        write("�ٳŵ�һ���㵫������������������\n");
                        ob->delete_temp("thd_marry");
                        ob->unconcious();
                        message("vision", "��ҩʦ������������������������Բ��ѵļһﶪ������ȥ��\n", environment(ob), ob);
                        ob->move(__THD__"haitan");
                        message("vision","��Ȼһ����ӿ�˹�������һ����ˮ�ݵð����ļһ�嵽�˰��ߡ�\n",environment(ob),ob);
                        return 1;
                }
                else
                        if (arg == "�Ҳ�֪��" || arg == "��֪��" || arg == "dunno") {
                                if (!present("yuxiao",this_object()))
if (obj = carry_object("/kungfu/class/taohua/obj/yuxiao")) obj->wield();
command("wield yuxiao");
                                command("sneer " + ob->query("id"));
                                command("say �ⶼ�𲻳�����\n");
                                write("��ҩʦ�ӻ���ȡ��һ֧����ŵ���ߴ�����������ãȻ��֪����Ϊ�Σ����һ����������\n");
                                write("��ҩʦ�ƺ��������Ӱ�죬����һ��Ͳ��ټ����ˡ�\n");
                                write("��ҩʦ˵�����ðɣ���ڶ��ؾ����Ǹ�ƽ�֡�\n");
                                write("��ҩʦ˵������Ҫ��׼�����˾����������ذɣ�\n");
                                tell_room(environment(ob), "��ҩʦ��" + ob->name() + "˵�
�����ðɣ���ڶ��ؾ����Ǹ�ƽ�֡�\n", ({ob}));
                                ob->set_temp("thd_marry", 3);
                                return 1;
                        }
                say("��ҩʦŭ�������ԣ�\n");
                return 1;
        }
        if (ob->query_temp("thd_marry") == 3)  {
                say(ob->name() + "�ڻ�ҩʦ�Ķ���С���ֹ���һ�䡣\n");
                if (arg == "��ʤʵ") {
                        command("chat* ̧ͷ���죬��˵���������⣬���⣬�����������أ���������֮�������澭���ң���ô�����Ҽ���һ�棿����������������������ô����");
                        write("��ҩʦ˵�����ðɣ�������ؾ�������ˡ�\n");
                        tell_room(environment(ob), "��ҩʦ��" + ob->name() + "˵�����ðɣ�������ؾ�������ˡ�\n", ({ob}));
                        write("��ҩʦЦ���еؿ����㣬�·����ڴ�ʲô��\n");
                        write("���ʱ���򣬹��������Ż�ҩʦ���������ؿ�������ͷ��������������������\n");
                        tell_room(environment(ob), ob->name() + "���������Ż�ҩʦ���������ؿ�������ͷ��������������������\n", ({ob}));
                        command("chat �ӽ�����" + ob->name() + "�����һ�ҩʦ��Ů���ˣ�");
                        payed = 0;
                        if (!ob->query("benefit/yaoshi") && !payed) {
                                write("��ҩʦ˵����С�ֵ��������ҵ�Ů�����Ϸ�����Ϊ�����͸��㽲Щ��ѧ�ĸ������ɡ�\n");
                                write("�����Ż�ҩʦ�Ľ��⣬��������֪��һ��ӡ֤����ʱ������������ѧ����\n");
                                if (ob->query("family/family_name") == "�һ���")
                                        ob->add("combat_exp", 18000);
                                else
                                        ob->add("combat_exp", 15000);
                                ob->set("benefit/yaoshi", 1);
                                payed = 1;
                        }
//                        write("��ҩʦ˵�������Ѿ����ʸ����ѧϰ������Ѩ���ˣ��Ȿͼ���͸��㡣\n");
//                        new(__THD__"obj/shoufa.c")->move(ob);
                        ob->delete_temp("thd_marry");
                        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                                nvxu = load_object("/clone/npc/huang-son-in-law");
                        nvxu->do_copy(nvxu, ob);
                        return 1;
                }
                say("��ҩʦŭ�������ԣ�\n");
                return 1;
        }
        return 0;
}
void unconcious()
{
        command("chat* ��̾һ�������ݺὭ����ʮ�أ�����������а������ɥ����û�뵽Ҳ�н��죡");
        ::unconcious();
}
