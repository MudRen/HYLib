#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
        set_name("��ӥ", ({ "hawk" }) );
       set("title",HIR"��Į��ӥ"NOR); 
	set("gender", "����" );
        set("no_get",1);
        set("age", 22);
        set("long","������һ���߸ߵı�������ĸߴ����䣬������и�������������Ȥ��������������������磩����\n");
        set("combat_exp", 5000000);
  	 set("str",1000);
	
        set("attitude", "friendly");
        setup();
        carry_object("/clone/cloth/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
	if (interactive(ob = this_player()))
{
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}
        add_action("do_yang", "yang");
	add_action("do_return","return");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "��ӥ˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ�����ô��\n");
                        break;
                case 1:
                        say( "��ӥ˵������λ" + RANK_D->query_respect(ob)
                                + "����̫���ˣ����ҵı�����Զ�㡣\n");
                        break;
        }
}

int do_yang(string arg)
{
	string ctype, cname, ccolor, cid;
	object ob, me, gold;
	string id,filename;
	object newpet;
        me = this_player();
	id = me->query("id");
        if(!arg || sscanf(arg,"%s %s %s %s",ctype,ccolor,cname,cid ) != 4)
        return notify_fail("ָ���ʽ��yang <type> <color> <name> <english name>\n");
	if(me->is_busy())
	return notify_fail("����һ��������û����ɡ�\n");
	if(me->query("marks/pet") > 0)
	return notify_fail("���Ѿ�ӵ�����İ��ĳ����ˡ�\n");
	gold = present("gold", this_player());
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < 200)
        return notify_fail("������û���������ӡ�\n");
	if((int)me->query("score") < 100)
	return notify_fail("������۲�����\n");
	if( !check_legal_name(cname))
	return notify_fail("");
        if( !check_legal_id(cid))
        return notify_fail("");

	if( ccolor != "$BLK$" && 
	    ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
	)
	return notify_fail("��֪��Ҫʲô��ɫ��\n");
	cname = ccolor + cname;
        cname = replace_string(cname, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);
        cname += NOR;
	seteuid(ROOT_UID);
	newpet = new("/clone/npc/pet");	
	switch( ctype ) {
                 case "dog":
			newpet->set("title","С��");
			newpet->set("int",5+random(10));
                        break;
                case "cat":
		        newpet->set("title","Сè");
                        newpet->set("per",5+random(10));
                        break;
                case "pig":
                        newpet->set("title","С��");
                        newpet->set("str",5+random(10));
                        break;
                case "monkey":
                        newpet->set("title","С��");
                        newpet->set("kar",5+random(10));
                        break;
                case "hen":
                        newpet->set("title","С��");
                        newpet->set("con",5+random(10));
                        break;
                case "hawk":
                        newpet->set("title","Сӥ");
                        newpet->set("dex",5+random(10));
                        break;
		default:
			return notify_fail("���ﲻû����Ҫ�Ķ�����\n");
	}
	newpet->set("owner",me->query("id"));
	newpet->set("possessed",me);
	newpet->set("name",cname);
	newpet->set("id","pet "+cid);
	newpet->save();
	destruct(newpet);
	gold->add_amount(-200);
	me->add("score",-100);
        me->start_busy(1);
	me->set("marks/pet",1);
	command("say �����Ŵ�һ�����ڣ����������壩�����С�����ͻ��ܹ����ģ�\n");
        seteuid(getuid());
	return 1;
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("�Բ���Ӣ�����ֱ�����������ʮ���֡�\n");
                return 0;
        }

	return 1;
}
int do_return()
{object me;string file;
me=this_player();
	if(me->is_busy())
	return notify_fail("����һ��������û����ɡ�\n");
	//if(me->query("marks/pet") < 1)
	//return notify_fail("��û���Լ��ĳ����ˡ�\n");
	me->delete("marks/pet");
	seteuid(ROOT_UID);
	file = "/data/user/t/tiandi.pet.o";
	rm(file);
	seteuid(getuid());
	 write("�ϣ�\n");
return 1;
}	
void unconcious()
{
    die();
}
