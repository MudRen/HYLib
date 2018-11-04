inherit NPC;
int look_ob();
int ask_letter();
int do_suan(string str);
int ask_suanming();
string ask_mimi();
void create()
{
        set_name("������", ({ "shensuan zi", "shensuan" }) );
        set("nickname", "������");
        set("gender", "����");
        set("age", 66);
        set("long",
            "�����������ڰ��ͷſ��������˯������Һһֱ���������ӵ��¡�\n");
        set("attitude", "peaceful");
        set_skill("taoism", 300);
        set_skill("force",200);
        set("max_neili",5000);
        set("max_jingli",3000);
        set("letter", 1);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);
        set("combat_exp", 500000);
        set("shen_type", 1);

        set("inquiry", ([
            "����": (: ask_suanming :),
            "����": (: ask_mimi :),
            "��": (: ask_letter :),     
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();        
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("look_ob");
                call_out("look_ob", 6, ob);
        }
}
int look_ob()
{
    foreach (object player in all_inventory(environment()) )
        command("look "+player->query("id"));
    return 1;
}
int ask_suanming()
{
      if ((int)this_player()->query_temp("knock")) {
           command("whisper " +this_player()->query("id")+ " û����⣬�Ϸ�ˡ�Ѵ�����\n");
           this_player()->set_temp("knock", 0);
           return 1;
           }
    return 0;
}
string ask_mimi()
{
        object me=this_player();
        if(!me->query_temp("mimi")) return "�����Ҳ�֪��Ҳ��";
        me->delete_temp("mimi");
        me->set_temp("letter",1);
        return "�ܶ���ǰ���ҵ�үү��үү��������һ���ţ���֪������������һ�������ܡ�";
}
int ask_letter()
{
        object ob,me=this_player();
        int p1;
        if (query("letter") < 1)  say("�����Ӻ��ź���˵���������������Ѿ������ˡ�\n");
        if((int)me->query("passwd1")) {
        say("�����Ӻܲ��ͷ���˵�����Ұ���֪���Ķ��������ˣ�����ʲô�\n");
        }else 
        if ((int)me->query_temp("letter")) {
        say("�����Ӻٺٵļ�Ц�˼�������������Ҫ���������\n");
        write("��������ͷ���˻ᣬ˵�����ðɣ�\n");
        p1=random(6)+1;
        me->set("passwd1",p1);
        write("����ŵĺ����Ѿ��������ˣ�������Լ�ǵ�������ᵽ"+CHINESE_D->chinese_number(p1)+"��ʲô�����ġ�\n");
        write("�����ҾͰ�����Ž������ˣ��Ҷ�������Ѿ�ʧȥ��Ȥ�ˣ�������Ҫ���ذ�����\n");
        me->delete_temp("letter");
        add("letter", -1);
        ob=present("letter",this_object());
        if (!ob)
                ob=new("/d/changan/obj/letter.c");
        ob->move(me);
        }else{
        message("vision","�����Ӳ�֪������˵ʲôҲ����\n", me);
        }
        return 1;
}
int accept_object(object me, object ob)
{
        command("smile");
    command("say �ٺ٣���л��λ" + RANK_D->query_respect(me) + " ��");
    if( ob->query("money_id") && me->query("class") != "bonze" ) 
    {
        if(ob->value() < 1000000)
        {
            command("say ���������������������ǲ������ٸ���...");
            return 1;
        }else{
            command("smile shensuan");
            command("say " + RANK_D->query_respect(me) + "�����ң���Ҫ��(suan)�Լ���������˭��");
            add_action("do_suan","suan");
            me->set_temp("give_money",1);
            return 1;
        }
    }
    return 1;
}
int do_suan(string arg)
{
        object ob, me = this_player();
        string name;
        int str, ntg, dex, per, con, kar,str1, ntg1, dex1, per1, con1, kar1;

        if(!arg || sscanf(arg, "%s", name)!= 1 )   return 0;
        if(!me->query_temp("give_money")) return 0;        
        if(!objectp(ob = find_player(name)) )   return 0;
        if( !ob || wizardp(ob)) {
                command("tell "+me->query("id")+" �꣬С���㣬��������ô���㰡��");
                return 1;
        }

        me->delete_temp("give_money");
        str = ob->query("str");
        ntg = ob->query("int");
        dex = ob->query("dex");
        per = ob->query("per");
        con = ob->query("con");
        kar = ob->query("kar");
        str1 = ob->query_str();
        ntg1 = ob->query_int();
        dex1 = ob->query_dex();
        per1 = ob->query_per();
        con1 = ob->query_per();
        kar1 = ob->query_kar();


        switch(random(6)) {
                case 0 :
                if( str1+ntg1+dex1+per1+con1+kar1 > (ob->query("age")+6) * 6) {
                        command("nod");
                        command("say ����"+ob->name()+"Ҳ���������з���");
                } else {
                        command("sigh");
                        command("say "+ob->name()+"��Ҫ�ڻ������϶��µ㹦��");
                }
                break;
                case 1 :
                if(kar > 22) {
                        command("smile");
                        command("say "+ob->name()+"��Ե��񣬼����������ࡣ");
                }else {
                        command("hmm");
                        command("say "+ob->name()+"��һ��������ע��Ҫ����ĥ���ˡ�");
                }
                break;
                case 2 :
                if(ntg > 25 || ntg1 > 40+ob->query("age") ) {
                        command("nod");
                        command("say "+ob->name()+"���ʹ��ˣ����ܶ��Ŭ�����ض��ܳ���ͷ�ء�");
                } else {
                        command("shake");
                        command("say "+ob->name()+"���֪���������ȷɣ��ĵ��������л���ġ�");
                }
                break;
                case 3 :
                if(str > 25)
                        command("say "+ob->name()+"����������У���Ҳ���ѳ�Ϊһ��������");
                else    command("say "+ob->name()+"Ӧ��ר�������书��������̰�ࡣ");
                break;
                case 4 :
                if(per > 23 ) {
                        command("nod");
                        command("say "+ob->name()+"������ò�����ܼ����������ض��ܳ�������");
                }else {
                        command("shake");
                        command("say "+ob->name()+"��ò��Ȼ��ˣ�����ѰЩ��Ե�����ǿ������ݵġ�");
                }
                break;
                case 5 :
                if(dex1 > (ob->query("age")+60) ) {
                        command("nod");
                        command("say "+ob->name()+"�������࣬�Ѵ�һέ�ɽ������������¿๦�����ɴ���");
                }else {
                        command("shake");
                        command("say "+ob->name()+"�������أ��ڽ���������������Ҫ�ģ������˰�!");
                }
                break;
        }
        me->set_temp("mimi",1);
        return 1;
}

