// zhou.c �ܲ�ͨ

#include <ansi.h>
#include <skill.h> 
inherit NPC;
string *questions = ({
	"����ŷ����ľ�����ʲô��",
	"���Ͻл��Ǹ�����������Ʒ���ʲô��",
	"����а���Ӯ���õĹ�����ʲô��",
	"�ϸ�����������ִ�����Ĺ�����ʲô��",
	"��ʦ�ֵ������ڹ��ķ���ʲô��",
	"�ҽ�������Ľ�����ʲô��",
	"������ǧ����Ṧ��ʲô��",
	"������󡹦�Ŀ�����ʲô��",
	"����а����ʲô��ѧ���ҹ�������ģ�",
	"���Ͻл��Ĵ򹷰��������������һʽ��ʲô��",
	"���С�ֵ��Դ��Ĺ�����ʲô��",
	"�����µ�������ѧ��ʲô��",
	"��ң�ɵ��Ǹ��������������Ĺ�����ʲô��",
	"���������ֵ��Ṧ��ʲô��",
	"����ͷ�������Ľ�����ʲô��",
	"���̵������ѧ��ʲô��",
	"���Ͻл��Ľ���ʮ���������������һ����ʲô��",
	"��Գ���еľ�������ص���ʲô��ѧ��",
	"����а������Сͽ��͵ѧ�˾����澭��ʲô�书��",
	"�ϸ�����Դ��Ķ���ȭ����ʲô��"});
int ask_jieyi();
int ask_hubo();
int do_fangyuan();
int do_learn(string arg);
int ask_jiuyin();
int ask_story();
int ask_story2();
int ask_quest();
int do_answer(string arg);
int ask_kungfu();

void create()
{
        set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "bo tong" }));
        set("gender", "����");
        set("nickname", CYN "����ͯ" NOR ) ;
        set("title", "ȫ��̵�һ������") ;
        set("age", 45);
        set("long",
        "�������˳ơ�����ͯ�����ܲ�ͨ��\n"
        "��������ȫ��������˵�ʦ�ܣ��书��ǿ��������ȴ����������\n"
        "��ССɽ��֮�У�ͷ�����ӳ����ģ�ë���׵���һ��Ұ�ˡ�\n",
        );

        set("no_get",1);
        set("combat_exp", 9000000);
        set("shen_type", 1);
        set("double_attack", 1);
        set("max_neili", 15000);
        set("neili", 15000);
        set("jiali", 0);
        set("qi", 26500);
        set("max_qi", 26500);
        set("jing", 25400);
        set("max_jing", 25400);
        set("neili", 59000);
        set("max_neili", 59000);
        set("jiali", 100);

        set("combat_exp", 8000000);
        set("score", 500000);
        set_skill("cuff", 300);
        set_skill("strike", 300);
        set_skill("force", 300);
        set_skill("sword", 300);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hubo" ,300);
        set_skill("qixing-array",380);
        set_skill("kongming-quan",380);
        set_skill("quanzhen-jian",350);
        set_skill("xiantian-qigong", 380);    //��������
        set_skill("haotian-zhang", 380);    //�����
        set_skill("jinyan-gong", 380);   //���㹦
        map_skill("unarmed","kongming-quan");
        map_skill("parry","kongming-quan");
        map_skill("dodge","jinyan-gong");
        map_skill("force","xiantian-qigong");
        set("double_attack", 1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.kong" :),
                (: perform_action, "unarmed.luanwu" :),                	
                (: perform_action, "unarmed.ruo" :),                	                	
                (: exert_function, "powerup" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "powerup" :),                
        }));
        set_temp("apply/attack", 200);
        set_temp("apply/defense",200);
        set_temp("apply/armor", 550);
        set_temp("apply/damage", 220);

        set("inquiry", ([
                "��а": "�ǻ�ҩʦ����޳ܵļһƭ���ҵľ�....ȥ����",
                "��ҩʦ": "����޳ܵļһƭ���ҵľ�....ȥ����",
                "����ͨ": "�ҵ�ʦ���������书��ߵģ���һ�λ�ɽ�۽�ʱ����Ϊ��һ���֡�",
                "������": "�ҵ�ʦ���������书��ߵģ���һ�λ�ɽ�۽�ʱ����Ϊ��һ���֡�",
                "�ܲ�ͨ": "������ʲô����",
                "����": "���Ż���ԧ��֯����˫��....",
                "����": "���Ż���ԧ��֯����˫��....",
                "�λ�ү": "����ͯ���¶Բ�������û���ټ����ˡ�",
                "������": "����ͯ���¶Բ�������û���ټ����ˡ�",
                "�ϵ�": "����ͯ���¶Բ�������û���ټ����ˡ�",
                "����ͯ": "�Ҿ��ǰ���������ʲô����",
                "����ȭ": "����ȭ����ʮ��·���ھ��ǣ��������ɡ���ͨ���Ρ�������Ū��ͯӹ���档",
                "kongming-quan": "����ȭ����ʮ��·���ھ��ǣ��������ɡ���ͨ���Ρ�������Ū��ͯӹ���档",
                "����": "�Ǽ�����ǰ������������Ǹ�С������",
                "����": "�����ҵĽ����ֵܣ�����Ȼɵ���ĳ����á�",
                "��": "��Ҫ������",
                "fang": "��Ҫ������",
                "Բ": "ԲҪ��Բ��",
              	"�����澭": (: ask_jiuyin :),
                "˫�ֻ���": (: ask_hubo :),
                "���һ���": (: ask_hubo :),
                "����": (: ask_jieyi :),
                "���": (: ask_jieyi :),
                "����": (: ask_story :),
                "��������": (: ask_story2 :),
		"����": (: ask_quest :),
		"����": (: ask_kungfu :),

        ]) );

        create_family("ȫ���", 1, "����");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob = this_player();
        add_action("do_fangyuan","fangyuan");
        add_action("do_draw","draw");
        add_action("do_draw","hua");
        add_action("do_learn","learn");
        add_action("do_learn","xue");
        add_action("do_answer","answer");
        ::init();
        if (ob->query("family/family_name") == "ȫ���") {
                command("angry " + ob->query("id"));
                command("say ��ô�㵽����������ң��������Ҿ�ȥ�ʹ���˵��������ƨ�ɡ�");
        }
}

void kill_ob(object me)
{
        command("chat* crazy " + me->query("id"));
        ::kill_ob(me);
}

void unconcious()
{
        command("chat ̾��������ͯ������Ҫ�����ˣ�������������ֻ���ܣ���Щ��ͷ���޳���һ���Ƶ�Ī�������ɫ��䡣");
        ::unconcious();
}

int ask_story()
{
        object me = this_player();
        string msg;
	if (me->query_temp("jiuyin/fanhe") && !me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/shang-failed") < 3) {
	        msg = HIY"�ܲ�ͨ����$NҪ�������£���ʱ�˸߲��ҡ�\n"NOR;
	        msg+= HIY"�ܲ�ͨ��ʼ��������澭�ͻ��ѵĹ��¡�\n"NOR;
	        msg+= HIW"�ܲ�ͨ��$N���ʺ����������������˵�ˡ�\n"NOR;
	        message_vision(msg, me);
	        me->delete_temp("jiuyin/fanhe");
	        me->set_temp("jiuyin/story",1);
	        return 1;
	}
        return 0;
}

int ask_story2()
{
        object me = this_player();
        string msg;
        if (me->query_temp("jiuyin/story")==1)
        {
                msg = HIY"�ܲ�ͨһ��$N���������������ֿ�ĭ��ɵ�˵������\n";
                msg+= HIY"�ܲ�ͨ�����ֿ�ʼ��$N˵������ȫ��̵Ĺ��¡�\n";
                msg+= HIW"$N���ţ�Ҳѧ����Щȫ���������Ƥë��\n"NOR;
                msg+= HIC"�ܲ�ͨ˵����£������ĵ��ʵ������ֵܣ��������㼸������ɣ�\n"NOR;
                message_vision(msg, me);
                me->set_temp("jiuyin/story",2);
                return 1;
        }
        return 0;
}

int ask_jieyi()
{
        object ob=this_player();
        if (ob->query("zhou/jieyi")) {
                command("? " + ob->query("id"));
                command("say �������ǽ�ݹ�����");
                return 1;
        }
        if (ob->query("zhou/fail") >=3 ){
                command("hmm");
                command("say �Ҳ���˵�ˣ���û��Ȥ�����ݰ���");
                return 1;
        }
//        if (ob->query("age") > 30){
//                command("shake");
//                command("say ������ֻͯϲ�����������棬�����ݣ�û��˼��û��˼��");
//                return 1;
//        }
        if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
                if (ob->query("age") > 45) 
                        command("say �ұ���Ҳ�������ݣ����ǲ�֪���ֵ���ƻ��ǽ����ƣ�");
                else
                        command("say �ұ���Ҳ�������ݣ����ǲ�֪���ֵ���ƻ���������ƣ�");
                command("laugh");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ( ob->query("class") =="bonze" ){
                command("monk "+ ob->query("id"));
                command("say "+RANK_D->query_respect(ob)+"������ͯ�ҿ�û����Ȥ�����ݡ�");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ( ob->query_skill("literate", 1) > 100) {
                command("shake");
                command("say ������˹��龫������׼����ʲô�����ء�");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ((int)ob->query("shen") <= -1) {
                command("shake");
                command("say ����Ȼ������㣬��ʦ��̻岻����������а֮������Ҫ����ġ�");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ( ob->query("combat_exp") < 100000){
                command("shake "+ ob->query("id"));
                command("say ��λ"+RANK_D->query_respect(ob)+"�������ʵ��̫����ˣ��ҿ�û��Ȥ�����ݡ�");
                return 1;
        }
        if (random(ob->query("kar")) < 20){
                command("shake");
                command("say ������û�пգ�Ҫ�������������棿");
                ob->add("zhou/fail", 1);
                return 1;
        }
        command("nod " + ob->query("id"));
        if (ob->query("gender") == "����") {
                command("say �ðɣ����Ҿͽ��Ϊ�ֵܰɡ�");
        }
        else if (ob->query("gender") == "Ů��") {
                if (ob->query("age") > 48) 
                        command("say �ðɣ����Ҿͽ��Ϊ��ܰɡ�");
                else
                        command("say �ðɣ����Ҿͽ��Ϊ���ðɡ�");
        }
        message_vision("�ܲ�ͨ��$N�����������˵����������ͯ�ܲ�ͨ��������" + ob->name() +"���������պ��и��������ѹ�����\n"+
                       "����Υ�����ģ������书ȫʧ����С��СèҲ�򲻹�����\n", ob);
//        log_file("ZHOU",sprintf("%s(%s)���ܲ�ͨ����ڣ� %s\n",ob->name(1), getuid(ob), ctime(time())));
        ob->set("zhou/jieyi", 1);
        return 1;
}

int ask_jiuyin()
{
        object me=this_player();
	object ob;

	if (me->query("jiuyin/full")) {
		if(present("jiuyin zhenjing", me)) {
	                command("? " + me->query("id"));
	                command("say �����Ѿ���������");
	                return 1;
	        } else {
			ob = new("/clone/book/jiuyin-book.c");
			ob->move(me);
			message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ��������澭������\n"NOR, users());
	                command("say �úñ��ܣ����˿ɱ����������ˡ�");
			return 1;
		}
	}
        command("say ����������ʲô����");
        return 1;
}

int ask_hubo()
{
        object ob=this_player();
        int hubo;
        if(!ob->query("zhou/jieyi")){
                tell_object(ob,"�ܲ�ͨ�������㿴����֪����Щʲô���⡣\n");
                command("say ����˭������ôĪ�����������˫�ֻ������°���");
                return 1;
        }               
        if (ob->query("double_attack")) {
                command("? " + ob->query("id"));
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if(ob->query("zhou/failed") >= 3){
                command("disapp " + ob->query("id"));
                command("say �Ѿ�������ô��Σ�������һ����Ҳ���������Ź����ˡ�");
                return 1;
        }
        hubo = ob->query_temp("zuoyou_hubo");
        if (hubo == 22) {
                command("say ��������һ�Σ�");
                return 1;
        }
        if (hubo == 1) {
                command("say ��������Ϳ����");
                return 1;
        }
        if (hubo > 1 && hubo <= 21) {
                command("say ��ô����������ɣ����������Ů����������͸��һ���Ķ�������ʮ�߰˸��ϣ��������Ź�������ʼ��ѧ���ᣡ");
                return 1;
        }
        if (ob->query_skill("force") < 100 || ob->query("max_neili") < 500 || ob->query("combat_exp") < 10000) {
                command("say �㻹���ȴ����ѧ������˵�ɡ�");
                return 1;
        }
        command("say ���Ź��������ڶ�������֮ʱ��������������˵�����ѵ�������˵����Ҳ����֮����\n"+
                "�е���һѧ��ᣬ�е���һ����Ҳѧ���ˣ�Խ�Ǵ�����Խ�ǲ��ɡ�");
        command("say �����������һ�Σ����ֻ���(fang)�����ֻ�Բ(yuan)��");
        ob->set_temp("zuoyou_hubo", 1);
        return 1;
}


int do_fangyuan()
{
        object ob=this_player();
        int hubo;
        if (ob->is_busy() || ob->is_fighting()) return notify_fail("����æ���أ�\n");
        hubo = ob->query_temp("zuoyou_hubo");
        ob->start_busy(1);
        if (!hubo) return 0;
        if (hubo < 21) {
                message_vision("$N�������ʳָ�ڵ��ϻ��������������ķ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
                ob->add_temp("zuoyou_hubo", 1);
                return 1;
        }
        if (hubo == 21) {
                message_vision("$N�������ʳָ�ڵ��ϻ��������������ķ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
                command("haha " + ob->query("id"));
                command("say ��ô������һ�±�첻����");
                ob->add_temp("zuoyou_hubo", 1);
                return 1;
        }
        if (hubo == 22) {
                if ( ob->query("kar") > 40 ){
                    if( random(ob->query("kar")) > 30 && random(20)==0){
                        message_vision("$N΢΢һЦ��������һ���ĵؿ���������������˫����ָ�����ֻ���һ�����飬���ֻ���һ��ԲȦ��\n"+
                                       "����������Բ�߻�Բ��\n", ob);
                        say("�ܲ�ͨ���һ�������˰��βŵ������ⶨ�������̥��ѧ���ı��죬�Ǳ��װ��ˡ���\n");
                        message_vision("�ܲ�ͨ����������������������ޱȵ��湦��һ���Զ����̸���$N��\n", ob);
                        ob->delete_temp("zuoyou_hubo");
//                        log_file("ZHOU",sprintf("%s(%s)���ܲ�ͨ������˫�ֻ����ڣ� %s\n",ob->name(1), getuid(ob), ctime(time())));
                        ob->set("double_attack", 1);
                        return 1;
                    }
                    else {
                        ob->delete_temp("zuoyou_hubo");
                        message_vision("$N���������ʳָ�ڵ��ϻ����������������Ծ��Ƿ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
                        write("������������ô�򵥡�\n");
                        ob->add("zhou/failed", 1);
                        return 1;
                    }
                }
                message_vision("$N���������ʳָ�ڵ��ϻ����������������Ծ��Ƿ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
                message_vision("$N���ڷ����Լ���һ����Ҳ���������Ź����ˡ�\n", ob);
                ob->delete_temp("zuoyou_hubo");
                ob->add("zhou/failed", 1);
                command("disapp " + ob->query("id"));
                return 1;
        }
        return 0;
}

int do_draw(string arg)
{
        object ob=this_player();

        if (!ob->query_temp("zuoyou_hubo")) return 0;
        if (arg == "fang" || arg == "��" || arg == "yuan" || arg == "Բ") return notify_fail("�ܲ�ͨŭ��������ͬʱ����Բ��\n");
        if (arg == "fang yuan" || arg == "��Բ") return do_fangyuan();
        return 0;
}

int do_learn(string arg)
{
        object me=this_player();
        string skill, teacher, skill_name;
        object ob;
        int master_skill, my_skill, gin_cost, rand;

        if (me->is_busy())
                return 0;

        if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
                return 0;

        if (teacher != "zhou" && teacher != "botong")
                return 0;

        if( me->is_fighting() )
                return 0;

        if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
                write("��Ҫ��˭��̣�\n");
                return 1;
        }

        if( !living(ob) ) {
                write("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
                return 1;
        }

        if( !me->query("zhou/jieyi")) {
                write("�ܲ�ͨ��ֵؿ����㣬�ʵ�������˭ѽ��\n");
                return  1;
        }

        if (skill != "kongming-quan" && skill != "����ȭ") {
                write("���������±����ұ���ѧ�ˡ�\n");
                return 1;
        }

        my_skill = me->query_skill(skill, 1);
        master_skill = ob->query_skill(skill, 1);
        if( my_skill >= master_skill ) {
                write("���ڿ���ȭ�ϵ������Ѿ���������ͯ�ˣ�\n");
                return 1;
        }

        if( !SKILL_D(skill)->valid_learn(me) ) {
                write("������ǿ��ֲ������㹻���ڹ��������ſ���ѧϰ����ȭ��\n");
                return 1;
        }

        gin_cost = 150 / (int)me->query("int");

        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }

        rand = random(20);
        if (rand == 4)
                gin_cost *= 2;
        else if (rand == 15)
                gin_cost += 4;
        if( (int)me->query("potential") < 1 ) {
                write("���Ǳ���Ѿ����ӵ������ˣ�û�а취��ѧ�ˡ�\n");
                return 1;
        }

        message_vision("$N��$n����йء�����ȭ�������⡣\n", me, ob);

        if( (int)me->query("jing") > gin_cost ) {
        write("�ܲ�ͨ��������ӡ����¾������о仰��������ֲ��Ϊ���������ޣ�����֮�á��仧���Ϊ�ң������ޣ�����֮�á���\n");
                write("�ܲ�ͨ���ھ����������ȱ�����ò��ף���ӯ���壬���ò��\n");
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        write("Ҳ����ȱ��ʵս���飬�������ͯ�Ľ��������޷���ᡣ\n");
                } 
                else {
                        if (rand == 13) {
                                write("��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
                                write("�����ʲô��ûѧ����\n");
                                return 1;
                        }
                        else if (rand == 5) {
                                write("�ܲ�ͨ���������䣬��Ȼ���ͷ�������������������������ĸ��˴�ܿɺã���\n");
                                write("�����ֻ��������ˣ��һ��\n");
                                return 1;
                        }
                        else if (rand == 4) {
                                write("��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
                                write("����㻨�˱�ƽ����һ���ľ�����\n");
                        }
                        else if (rand == 15) {
                                write("��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
                                write("����㻨�˱�ƽ����ö�ľ�����\n");
                        }
                        if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                                write("����������ͯ��ָ�����ԡ�" + skill_name + "����һ���ƺ���Щ�ĵá�\n");
                        else
                                write("����������ͯ��ָ�����ƺ���Щ�ĵá�\n");
                        me->add("potential", -1);
                        me->improve_skill(skill, random(me->query_int()));
                }
	}
        else {
                gin_cost = me->query("jing");
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
        }

        me->receive_damage("jing", gin_cost );

        return 1;
}

void finish(object me)
{
	me->delete_temp("jiuyin/asking");
	me->delete_temp("jiuyin/question");
	me->delete_temp("jiuyin/story");
	if (me->query_temp("jiuyin/count") > 0 && random(me->query_temp("jiuyin/count")) > 10 && !random(20)) {
		me->delete_temp("jiuyin/count");
		me->set_temp("jiuyin/passed", 1);
		command("admire " + me->query("id"));
		command("say ԭ��������ͬ�����˰���");
		command("hoho");
		message_vision("\n", me);
		command("say ������������ô�ã�һ�������İɣ�");
		command("hmm");
		command("ah " + this_object()->query("id"));
		command("say �����ɣ��ҽ�������Ĺ���");
		command("grin");
	} else {
		me->delete_temp("jiuyin/count");
		me->add("jiuyin/shang-failed", 1);
		command("disapp");
		command("say ���ϧ����ļ���ʵ��̫��´�����������ɡ�");
	}
}

int ask_quest()
{
        object me = this_player();
        if (me->query_temp("jiuyin/story") == 2)
        {
		if (me->query_temp("jiuyin/asking")) {
			command("say ���ǲ���������ô��ר�ĵ㣡");
			command("kick " + me->query("id"));
	                return 1;
		}
		me->set_temp("jiuyin/asking", 1);
		me->set_temp("jiuyin/count", 0);
		command("say ׼���ã����ǿ�ʼ����");
	 	call_out("ask_question", 1, me);
	 	call_out("finish", 60, me );
		return 1;
        }
        return 0;
}

int do_answer(string arg)
{
        object me = this_player();
        string answer;

	if (!me->query_temp("jiuyin/asking") || !me->query_temp("jiuyin/question"))
		return 0;
        if( !arg || arg=="" ) {
           write("��ô��ٻش�\n");
           return 1;
        }
        switch ((int) me->query_temp("jiuyin/question")) {
          case 1: answer="hamagong"; break;
          case 2: answer="xianglong-zhang"; break;
          case 3: answer="tanzhi-shentong"; break;
          case 4: answer="hubo"; break;
          case 5: answer="xiantian-qigong"; break;
          case 6: answer="qixing-array"; break;
          case 7: answer="shuishangpiao"; break;
          case 8: answer="yiyang-zhi"; break;
          case 9: answer="qimen-wuxing"; break;
          case 10: answer="wugou"; break;
          case 11: answer="anran-zhang"; break;
          case 12: answer="six-finger"; break;
          case 13: answer="beiming-shengong"; break;
          case 14: answer="lingboweibu"; break;
          case 15: answer="lonely-sword"; break;
          case 16: answer="qiankun-danuoyi"; break;
          case 17: answer="kanglongwuhui"; break;
          case 18: answer="jiuyang-shengong"; break;
          case 19: answer="jiuyin-baiguzhua"; break;
          case 20: answer="kongming-quan"; break;
        }
	if (arg == answer) {
		me->add_temp("jiuyin/count", 1);
		command("say �������е�ͷ���");
		command("praise " + me->query("id"));
	} else {
		me->add_temp("jiuyin/count", -1);
		command("say ��");
		command("papaya " + me->query("id"));
	}
	command("say ����һ��ɡ�");
	me->delete_temp("jiuyin/question");
 	call_out("ask_question", 1, me);
        return 1;
}

void ask_question(object me)
{
	int quest;
	if (me->query_temp("jiuyin/asking")) {
		message_vision("\n", me);
		command("say ע�������ˣ�");
		message_vision(HIW"�� answer ���ش𣬻ش���ʹ��ƴ�����룬��Ҫ�ú��֡�\n"NOR, me);
		quest = random(20);
		command("say " + questions[quest]);
		message_vision("\n", me);
		me->set_temp("jiuyin/question", quest+1);
	}
	return;
}

int accept_object(object who, object ob)
{
	if ((string)ob->query("id") == "fan he") {
		command("say �ǻ���а��СѾͷ�����æ�ͷ���ô��");
		message_vision(HIC"�ܲ�ͨ����$N�ش��Ѿ���ʼ��ʳ���������С�\n"NOR, who);
		message_vision(HIC"�ܲ�ͨ���꣬��Ц��һ�£��Ŷ�$N�ʵ�������֪����Թ���û�У�\n"NOR, who);
		command("say ����а��Ҫ�ҵľ����澭�����ҹ���ʮ��������");
		command("sing3");
		command("say ���벻��������˵���£�");
		call_out("destroying", 1, ob);
		who->set_temp("jiuyin/fanhe", 1);
		return 1;
	}
	if (who->query("jiuyin/xia") && (string)ob->query("id") == "jiuyin xiajuan") {
		command("ah " + who->query("id"));
		command("say �������ұ�����аƭȥ�ľ����澭�¾�");
		command("say ��֪������û���õ��Ͼ��أ�");
		call_out("destroying", 1, ob);
		who->set_temp("jiuyin/give", 1);
		return 1;
	}
	if (who->query("jiuyin/shang") && (string)ob->query("id") == "jiuyin shangjuan") {
		if (!who->query_temp("jiuyin/give")) {
			command("say �Ȿ�����澭�Ͼ��㲻��Ҫ�ˣ�");
			return 0;
		}
		who->delete_temp("jiuyin/give");
		call_out("destroying", 1, ob);
		message_vision(HIC"�ܲ�ͨ�����ϵľ����澭���Ͼ���¾�϶�Ϊһ��\n"NOR, who);
		command("say �ֵܣ��ҾͰ��Ȿ�����澭�������ˣ����Ҫ�úñ�������");
		who->delete("jiuyin/shang");
		who->delete("jiuyin/xia");
		who->set("jiuyin/full", 1);
		new("/clone/book/jiuyin-book.c")->move(who);
		message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+who->query("name")+"�õ��������澭������\n"NOR, users());
		return 1;
	}
	return 0;
}

void destroying(object obj)
{     
	if (!obj) return;
	destruct(obj);
}

int ask_kungfu()
{
        object me = this_player();
	if (me->query_temp("jiuyin/passed")) {
		me->delete_temp("jiuyin/passed");
		command("say ��Щ���������Լ��Ĵ������������ĺܰ���");
		if (me->query("kar") > 40 && random(10) == 0) {
			command("say �ϴ��������������а�������󣬾Ͱ�����������ˡ�");
			command("say �������Լ�ȥ�õģ�˭֪���Ǹ��������а�������������������ˡ�");
			command("say �ҿ�С�ֵܵ��������󲻴����Լ�ȥ���԰ɣ�");
			me->delete("jiuyin/shang-failed");
			me->set("jiuyin/shang", 1);
		} else {
			command("heihei " + this_object()->query("id"));
			message_vision(HIC"�ܲ�ͨȴֻ�Ǹ���$N���ʩչ����ȫ��������$N����\n", me);
			message_vision("$N������ô��ϰ�����޷��ɹ���\n"NOR, me);
			command("sigh");
			command("say ��������书�����ű���ѧ�˰ɡ�");
			me->add("jiuyin/shang-failed", 1);
		}
		return 1;
	}
	return 0;
}
