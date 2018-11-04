// logind.c

#define VISITORS "/log/mud/MUDVISITOR"
#define GIFTCARD "/log/mud/GIFTCARD"
#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
static string loginnip;
static int loginntime;

int check_legal_password(object ob,string arg);
int wiz_lock_level = WIZ_LOCK_LEVEL;
//tentop
int mad_lock = 0;
//10 
string Rname;
string *banned_name = ({
	"��", "��", "��", "��", "��", "��", "��", "��", "��",
	"����ү", "������", "����", "ʱ��", "��",
        "������", "��Сƽ", "����", "���Ż�",
        "�Լ�", "ĳ��", "ʬ��", "����","����", "����", "���",
        "�����", "ȥ���", "ë��", "��ʦ", "�����̵�",
	"����", "�����п�", "����", "���","����","С����","�ܱ�","������","�¼ұ�"
});
string random_name(int gender) //gender ==2 �ձ��� gender==1 Ů�� gender==0 ����
{
	string sname,sid;
	int i;
	string *first_name = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","ʩ","��","��","��","��","��","��","κ","��","��","��",
"л","��","ˮ","��","��","��","��","��","��","³","Τ","��","��","��","��","Ԭ",
"��","��","��","ʷ","��","��","�","Ѧ","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","Ԫ","��","��","��","��","Ф","��","Ҧ","��",
"��","��","ë","��","��","��","��","��","��","��","é","��","��","��","��","��",
"��","��","��","��","��","��","��","��","¬","��",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","�ʸ�","ξ��","����","̫��","����",
"����","ԯ��","���","����","����","����","Ľ��","˾ͽ","ʦ��","����","��ֺ","�й�",
"����","����","΢��","����","����","����","����","�Ϲ�",
});
	string *second_name1 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});
	string *second_name2 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});
	string *girl_name = ({ //Ů��ר��
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","�","��","��","��","��","��","��","��","��",
"ٻ","Ƽ","��","ϼ","��","��","��","Ӣ","��","��","��",
"��",
});
	string *japan_name1 =({
"ɽ��","����","����","��","����","����","��֥","��","��Ұ","ɽ��",
"��ľ","�ڲ�","С��","����","����","ǳ��","����","��ĩ","����","���",
"����","����","����","����"
});
	string *japan_name2 =({
"̫��","����","����","����","����","ʮһ��","ʮ����","��ʮ��","����",
"����","Ӣ��","ұ��","����","����","���","��һ","Ӣ��","��ʯ","�弪",
"һҶ","�ӹ�","����","����","��԰","��ˮ","���","���","Т��","ï",
"��","��","����","����","����","ɽ��","�ζ�","����","����"
});
gender=random(3);
	switch(gender){
	case 0:
	i = random(sizeof(first_name));
	sname = first_name[i]+second_name1[random(sizeof(second_name1))]+second_name2[random(sizeof(second_name2))];
		break;
	case 1:
	i = random(sizeof(first_name));
	sname=first_name[i]+second_name1[random(sizeof(second_name1))]+girl_name[random(sizeof(girl_name))];
		break;
      	case 2:
	i = random(sizeof(japan_name1));
	sname = japan_name1[i]+japan_name2[random(sizeof(japan_name2))];
	break;
	}
	return sname;
}
void get_id(string arg, object ob);
void confirm_id(string yn, object ob);
object make_body(object ob);
init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int howmany_user();
int howmany_visitor();
int howmany_card();
void set_visitor(int num);
void set_card(int num);
// tentop
int howmuch_money(object ob);

void random_gift(mapping my, int select)
{
	int i = 10, j;
	int tmpstr, tmpint, tmpcon, tmpdex;

	tmpstr = tmpint = tmpcon = tmpdex = 10;

	switch (select) {
		case 1: tmpstr = i = my["str"]; break;
		case 2: tmpint = i = my["int"]; break;
		case 3: tmpcon = i = my["con"]; break;
		case 4: tmpdex = i = my["dex"];
	}
	i = 50 - i;
	while (i--) {
		j = random(4);
		if (j == select - 1) {
			i++;
			continue;
		}
		switch (j) {
			case 0: tmpstr++; break;
			case 1: tmpint++; break;
			case 2: tmpcon++; break;
			case 3: tmpdex++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
	// next 3 are randomly selected
	my["kar"] = 10 + random(21);
	my["per"] = 10 + random(31);
}
void create() 
{
	seteuid(getuid());
	set("channel_id", "���߾���");
}

void logon(object ob)
{
	object *usr;
	int i, login_cnt;
        string welcome_msg;

// ��ֹ�ж��������� KMUD �ȹ��ߵ���
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	login_cnt = 0;
	while (i--) if (query_ip_number(usr[i]) == query_ip_number(ob)) login_cnt++;
	if (login_cnt > 3) {
		destruct(ob);
		return;
	}
//welcome_msg = "/adm/etc/welcome";
//write(read_file(welcome_msg));

// Add by Yu Jue 1997.8.6
        write("\n���ǽ���ʹ�� 800 * 600 �ķֱ��ʽ���"+MUD_NAME+"��\n");
    write(HIW"Best view with 800 * 600    "NOR);
    write("\n����ʹ��5555,2000,2002,2003,2004����˿ڽ���"+MUD_NAME+"��");
    write(HIW"\nCan use port 5555,2000,2002,2003,2004 telnet this Game      ��"NOR);
    write("\nPlease select ������ ��GB�� or �j���X ��Big5�� (GB/Big5):\n");
//    write("\nAre you using BIG5 font [Y|N]?");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}

	input_to("gb_big5", ob);
}

void gb_big5(string arg, object ob)
{
	int encode;
	object *usr,*usert;
	int i, inv_wiz_cnt, wiz_cnt, ppl_cnt, login_cnt;
        int iplimit,max_online,avg_online,ipl;
        int user_num;
//add by login
	mapping mud_list;
        mapping mud_svc;
        mixed *muds;
        string output,online_num,avg_num;
        int loop, size, total, count=0, p_count=0;
//
//	if( arg[0]=='y' || arg[0]=='Y' ) ob->set_temp("big5", 1);
//	if( arg[0]=='n' || arg[0]=='N' ) ob->set_temp("big5", 0);
	if(!arg || arg=="") {
	    write("\nPlease select ������ ��Gb�� or �j���X ��Big5�� (Gb/Big5):");
	    input_to( "gb_big5", ob );
	    return;
	}
	else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    encode=1;
	else {
	    write("\nPlease select ������ ��Gb�� or �j���X ��Big5�� (Gb/Big5):");
	    input_to( "gb_big5", ob );
	    return;
	}

	if(encode==0)
		write("\n��ӭ������"HIG"������II��"NOR"�Ĵ������硣\n\n");
	else
		write("\n�w��z�i�J"HIG"��MUD��"NOR"���ǩ_�@�ɡ�\n\n");
	ob->set_encoding(encode);
        write(read_file("/adm/etc/welcome"));

	if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
		write("��ĵ�ַ�ڱ� MUD ���ܻ�ӭ��\n");
		destruct(ob);
		return;
	}

//add by login
//      if( !find_object(DNS_MASTER) )
//		write("��·���鲢û�б����롣\n");
        mud_list = (mapping)DNS_MASTER->query_muds();

        mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

        if(!mud_list)
		write( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

        muds = keys( mud_list ) - ({ "DEFAULT" });

        muds = sort_array(muds, 1);
        
	output = 
"Mud                  ��������                ������·λַ     ����  ����\n"+
"������������������������������������������������������������������������\n";

	for(loop = 0, size = sizeof(muds); loop<size; loop++)
	{
		if( mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION )
			continue;
                if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
                                continue;
                }
                count = loop;
                if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
                        output += BBLU+HIW;
                else
                        output += WHT;

                if( undefinedp(mud_list[muds[loop]]["MUDNAME"]) ) {
                        output +=  sprintf("%-43s  %-15s  %4s", 
                                upper_case(muds[loop]),
                                mud_list[muds[loop]]["hy.21sun.net"],
                                mud_list[muds[loop]]["PORT"]);
                }
                else {
                        output +=  sprintf("%-20s %-23s %-15s  %4s", 
                                upper_case(muds[loop]),
                                undefinedp(mud_list[muds[loop]]["MUDNAME"])?
                                "":mud_list[muds[loop]]["MUDNAME"],
                                //mud_list[muds[loop]]["HOSTADDRESS"],
				mud_list[muds[loop]]["hy.21sun.net"],
                                mud_list[muds[loop]]["PORT"]);
                }
                if(!undefinedp(mud_list[muds[loop]]["USERS"]))
                {
				output+=sprintf("  %-4s", mud_list[muds[loop]]["USERS"] );
				if(sscanf(mud_list[muds[loop]]["USERS"], "%d", count)==1)
					p_count+=count;
		}
                else
                                output+=sprintf("  ----", mud_list[muds[loop]]["USERS"] );

                output +=NOR"\n";
                total ++;
        }
	output += "������������������������������������������������������������������������\n";
	output += sprintf("���� %d ��վ���뱾վ�����С����� %d ��������ߡ�\n",total==0?0:total-1,p_count);
//add end			

write("\n");
write(output);
//write(HIC"�κ�������飬�뵽���ǵ�Լ����̳����  \n"NOR);
//write("\n");
//write(output);

	UPTIME_CMD->main();

        usert=filter_array(children(LOGIN_OB), (: interactive :));
//	usr = filter_array(children(LOGIN_OB), (: interactive :));
	usr = users();
	wiz_cnt = 0;
	inv_wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
        ipl = 0;
        iplimit = 0;
	for(i=0; i<sizeof(usr); i++) {
                if( query_ip_name(usr[i])==query_ip_name(ob)) iplimit ++;
		if( !environment(usr[i]) ) login_cnt++;
	        else if( wizardp(usr[i]) && usr[i]->query("env/invisibility") ) inv_wiz_cnt++;
	        else if( wizardp(usr[i]) && !usr[i]->query("env/invisibility") ) wiz_cnt++;
		else ppl_cnt++;
	}

//Ŀǰ��ʱ����ÿIP�������15 ID
        if (iplimit>50 && query_ip_name(ob) != "NATSERV")
        {
		write("�Բ���" + MUD_NAME + "���IP���ӳ���12�û���лл��Ժ����֧�֣����ǻᾡ�촦��\n");
		destruct(ob);
		return;
        }

//Ŀǰ��ʱ����ÿIP�������15 ID
        if (iplimit>80 && query_ip_name(ob) == "NATSERV")
        {
		write("�Բ���" + MUD_NAME + "���IP���ӳ���80�û���лл��Ժ����֧�֣����ǻᾡ�촦��\n");
		destruct(ob);
		return;
        }

// ���� Start

/*        user_num=howmany_user();
        if(user_num!=0)
        {
            write(HIG"����II�ܹ��У�"+HIW+chinese_number(user_num)+HIW"���û���\n"+NOR);
        }

        user_num=howmany_visitor();
*/
	max_online = atoi(read_file(__DIR__"maxonline",1));

	avg_online = atoi(read_file(__DIR__"avguser",1));

	if(ppl_cnt+login_cnt+inv_wiz_cnt+wiz_cnt > max_online)

	   {

	   	online_num = sprintf("%d",ppl_cnt+login_cnt+inv_wiz_cnt+wiz_cnt);

	   	write_file(__DIR__"maxonline",online_num,1);

	   }

	   	avg_num = sprintf("%d",max_online - 40);

	   	write_file(__DIR__"avguser",avg_num,1);


        set_visitor(user_num+1);
        if (iplimit>1)
        write(HIG"���ĵ�ַ���У�"HIW+chinese_number(iplimit-1)+NOR+HIW"���û���");
// ���� End
//	write(HIG"�ܹ������˴Σ�" HIW + chinese_number(user_num));
	write(HIG"Ŀǰ�������ƣ�" HIW + chinese_number(MAX_USERS)+HIG +"                        ��MUDOS�汾�� " HIW + "MUDOS pre11 \n"+NOR);
        write(HIG"��Ϸ��ҳ��ַ��"HIW"Http://hy.21sun.net         "HIG"���´�����ҳ��"HIW"Http://www.21sun.net  \n"NOR);
//	write("\n");
//	UPTIME_CMD->main(1);
	printf(HIG"���������Ŀ��"HIW"%s"HIG"��                "HIG"ƽ��������Ŀ��"HIW"%s"HIG"�˹�\n"NOR,chinese_number(max_online),chinese_number(avg_online));
	printf(HIG"��ϷĿǰ���У�"HIW" %s "HIG"λ������ˡ�"HIW"%s "HIG"λ������Ů�����ϣ��Լ�"HIW" %s"HIG" λʹ���߳��������С�\n"NOR,
		chinese_number(wiz_cnt), 
                chinese_number(ppl_cnt+login_cnt+inv_wiz_cnt+wiz_cnt), 
                chinese_number(login_cnt+inv_wiz_cnt) );

	write("����Ӣ������(����ҿ���ѡ��һϲ��������)��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
	input_to( "get_id", ob );
}

void set_visitor(int num)
{
	if(num>0)
		write_file(VISITORS, sprintf("VISITORS %d", num), 1);
	else
		write("��ʦ��ע���������Ŀ����!\n");
	return;
}
void set_card(int num)
{
	if(num>0)
		write_file(GIFTCARD, sprintf("GIFTCARD %d", num), 1);
	else
		write("��ʦ��ע���������Ŀ����!\n");
	return;
}

int howmany_user()
{
	int i,j,ppl_cnt;
	string *dir , *ppls, name;
	mixed info;
	seteuid(getuid());
	ppl_cnt=0;
	dir=get_dir(DATA_DIR+"login/");
	for(i=0; i<sizeof(dir);i++)
	{
		reset_eval_cost();
		ppls=get_dir(DATA_DIR+"login/"+dir[i]+"/");
		ppl_cnt+=sizeof(ppls);
	}
	return ppl_cnt;
}

int howmany_visitor()
{
	int num=0;
	string content, format;
	content=read_file(VISITORS);
	sscanf(content, "%s %d", format, num);
	if(format!="VISITORS")
		write(format+"\n��ʦ��ע���������Ŀ����!\n");
	return num;
}
int howmany_card()
{
	int num=0;
	string content, format;
	content=read_file(GIFTCARD);
	sscanf(content, "%s %d", format, num);
	if(format!="GIFTCARD")
		write(format+"\n��ʦ��ע���������Ŀ����!\n");
	return num;
}

void get_id(string arg, object ob)
{
	object *usr;
	int i, login_cnt;
	object ppl; 

	arg = lower_case(arg);

	if( !check_legal_id(arg)) {
		write("����Ӣ������(����ҿ���ѡ��һϲ��������)��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("get_id", ob);
		return;
	}

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
//	&& sizeof(users()) >= MAX_USERS ) {
	&& sizeof(users()) > 400 ) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write("�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
			destruct(ob);
			return;
		}
	}
#endif
	if( wiz_level(arg) < wiz_lock_level ) {
		write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
			+ " ���ϵ��˲������ߡ�\n");
		destruct(ob);
		return;
	}	
	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

/*
if (arg!="hxsd")
{
        write("\nϵͳά���У���ȶ�Сʱ����!!\n");
         destruct(ob);
return;
}*/

	if( arg=="guest" ) {
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			write("���������룺");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
			input_to("get_passwd", 1, ob);
			return;
		}
		write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
		destruct(ob);
		return;
	}

// ��ֹ�������ϵ������ͬһ id
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
	if (i >= 0) {
		write("�������������ʹ����� ID�����������롣\n");
		write("����Ӣ�����֣�");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("get_id", ob);
		return;
	}
//ͬһIP login 1��
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && query_ip_number(usr[i])== query_ip_number(ob)) break;
	if (i >= 0) {
		write("��ͬһIP,������������ڵ�½��Ϸ,���һ���ٵ�½��\n");
         destruct(ob);
return;
	}

// Add by Yu Jue 1998.8.24

	write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
	input_to("confirm_id", ob);
}

void get_passwd(string pass, object ob)
{
	string my_pass;
	string ip = query_ip_number(ob);
	int time_rl;
	int time_pwd;
	object user;
        string temps;
	write("\n");
	my_pass = ob->query("password");
        time_rl = time() - ob->query("last_on");
        time_pwd = time() - ob->query("lastpwd");
	if (time_rl >= 0 && time_rl <= 60)
	{
		temps = sprintf("����ϴ��˳��� %d ��?\n", time_rl);
		write(temps);
			write("�Բ���Ϊ�˽���ϵͳ���ɣ����Ժ���login����л���ĺ�����\n");
	                destruct(ob);
	                return;
	}
if (ob->query("last_from")==ip)
{
		if (time_pwd >= 0 && time_pwd <= 10)
	{
		temps = sprintf("����ϴδ������,�� %d ��?\n", time_pwd);
		write(temps);
			write("�Բ���Ϊ�˱�֤ϵͳ��ȫ����һ���Ӻ���login����л���ĺ�����\n");
	                destruct(ob);
	                return;
	}
}
	if( crypt(pass, my_pass) != my_pass )
	{
		write("�������\n");
		ob->set("last_from", ip);
                ob->set("lastpwd", time());
                ob->save();
		destruct(ob);
		return;
	}


	// Check if logout recently

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
		if( user->query_temp("netdead") ) {
			reconnect(ob, user);
			return;
		}
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("confirm_relogin", ob, user);
		return;
	}

                if( ob->query("wizpwd") )
{
     write(HIR"��"WHT"��"HIG"��������Ӧ��WIZ����"WHT"��"NOR"");
                input_to("get_wizpwd", 1, ob);
}
		
	if( objectp(user = make_body(ob)) ) {
		if( user->restore() ) {
			log_file( "USAGE", sprintf("%s loggined from %s (%s)\n", user->query("name"),
				query_ip_name(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write("�������´���������\n");
	confirm_id("y", ob);
}

private void get_wizpwd(string pass, object user,object ob)
{
        string old_pass;
	object userp;
        write("\n");
        old_pass = user->query("wizpwd");
        userp = find_body(user->query("id"));

if (!user->query("wizpwd"))
{
   write(HIW"��û���趨WIZ���룬����WIZPWD���趨��\n"NOR);
}

if (user->query("wizpwd"))
{
   if(crypt(pass, old_pass)==old_pass ) {
                write(HIG"������ȷ��\n"NOR);
                return;
        }
else{
                write(HIR"�������\n"NOR);
                write(HIY"�������������ID�����룡\n"NOR);
		destruct(userp);
            input_to("get_id",user);
		return;
        }
}
}


void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("�ðɣ���ӭ�´�������\n");
		destruct(ob);
		return;
	} else {
if (user)
{
		tell_object(user, BLINK HIW"���˴ӱ�( " + query_ip_number(ob)
			+ " )����ȡ���������Ƶ����\n"NOR);
		log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
			query_ip_name(ob), ctime(time()) ) );
}
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link ) {
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);	
}

void confirm_id(string yn, object ob)
{
if (query_ip_name(ob)==loginnip
&& (time() - loginntime) <= 60)
{
        write("\n��MUDע��ͬһIP�����60����ֻ�ܽ���һ��!!,���Ժ���ע��!\n");
        destruct(ob);
return;
}
if (ob)
{
loginnip=query_ip_name(ob);
loginntime=time();
}
	if( yn=="" ) {
		write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}

		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("�ðɣ���ô��������������Ӣ�����֣�");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("get_id", ob);
		return;
	}
        write( @TEXT
[2J
[33m����������������������������������������������������������������
[41;33m		���´�������ע���򵼡�����һ��			[2;37;0m
[33m����������������������������������������������������������������[2;37;0m
[35m
���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵���������ɾ���������벻Ҫѡ���ӹС˵��
��������������
[37m
[31m
����������������������֣���ֱ���ûس����ۣңţԣգңΣݡ�
[37m
TEXT
	);
	write("������������(ʹ��Big5����ҿ�������ʦ�޸�)��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
	input_to("get_name", ob);
}

string display_attr(int gift)
{
	if (gift > 24) return HIY + gift + NOR;
	if (gift < 16) return CYN + gift + NOR;
	return "" + gift;
}

private void get_resp(string arg, object ob)
{
        if( arg=="" ) {
                write(WHT"������(y)������(n)����������֣�"NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
                input_to("get_resp", ob);
                return;
        }

        if( arg[0]=='y' || arg[0]=='Y' )
	{
        ob->set("name", Rname);
        write( @TEXT
[2J
[33m����������������������������������������������������������������
[44;33m		���´�������ע���򵼡����ڶ���			[2;37;0m
[33m����������������������������������������������������������������[2;37;0m
[35m
      ����ע��ĵڶ������趨��������룬�벻Ҫ��Ϊ�趨һ������
  �Ǻܼ򵥵��£������ϵ��������İ�ȫ������������˵��õĻ���
  ����һ���ǳ�Σ�յ��£���Ҫ��Ϊ�ⲻ���ܷ�����������һ��Ҫ����
  ��һ�������ױ��µ�������ź�Ŷ��
[32m
      Ϊ�˱�����ҵ����İ�ȫ�����´����������ϵͳ�ǳ��ϸ�
  ���е�Ҫ�����£�
[36m
  һ���������������ַ����ϡ�
  ���������б����������һ����д��ĸ��
  ���������б����������һ��Сд��ĸ��
  �ġ������б����������һ�����֡�
  �塢���벻�������Ӣ�����ֹ�������
  [33m
  �밴������Ҫ���趨������룬��������Ժ����Ϸ�����в�����ʧ
  �����룬�뷢��E-mail��hxsd@citiz.net��ȡ�����롣
  [37m
TEXT
        );
        write(WHT"�õģ��������趨�������룺"NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
        input_to("new_password", 1, ob);
	return;
	}
        else 
	if( arg[0]=='n' || arg[0]=='N')
	{
	Rname = random_name(random(2));
//	Rname = random_name();
        write(WHT"������(y)������(n)����������֣�"NOR);
        printf( HIY" -- %s ��"NOR, Rname);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}

        input_to("get_resp", ob);
	return;
	}
        else {
                write(WHT"�Բ�����ֻ��ѡ������(y)������(n)�� "NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
                input_to("get_resp", ob);
                return;
        }


}

private void get_name(string arg, object ob)
{
	string name;
        if( arg =="")
        {
	Rname = random_name(random(2));
//	Rname = random_name();
        write("������Ҫ������������������֣���\n");
        write("������(y)������(n)����������֣�");
        printf( HIY" -- %s ��"NOR, Rname);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
        input_to("get_resp", ob);
	}
	else {
        if( !check_legal_name(arg) ) {
		write("������������(ʹ��Big5����ҿ�������ʦ�޸�)��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
                input_to("get_name", ob);
                return;
        }

//        printf("%O\n", ob);
        ob->set("name", arg);
        write( @TEXT
[2J
[33m����������������������������������������������������������������
[44;33m		���´�������ע���򵼡����ڶ���			[2;37;0m
[33m����������������������������������������������������������������[2;37;0m
[35m
      ����ע��ĵڶ������趨��������룬�벻Ҫ��Ϊ�趨һ������
  �Ǻܼ򵥵��£������ϵ��������İ�ȫ������������˵��õĻ���
  ����һ���ǳ�Σ�յ��£���Ҫ��Ϊ�ⲻ���ܷ�����������һ��Ҫ����
  ��һ�������ױ��µ�������ź�Ŷ��
[32m
      Ϊ�˱�����ҵ����İ�ȫ�����´����������ϵͳ�ǳ��ϸ�
  ���е�Ҫ�����£�
[36m
  һ���������������ַ����ϡ�
  ���������б����������һ����д��ĸ��
  ���������б����������һ��Сд��ĸ��
  �ġ������б����������һ�����֡�
  �塢���벻�������Ӣ�����ֹ�������
  [33m
  �밴������Ҫ���趨������룬��������Ժ����Ϸ�����в�����ʧ
  �����룬�뷢��E-mail��hxsd@citiz.net��ȡ�����롣
  [37m
TEXT
        );
        write(WHT"�õģ��������趨�������룺"NOR);
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
        input_to("new_password", 1, ob);
		}
}

void new_password(string pass, object ob)
{
	write("\n");
       if( !check_legal_password(ob,pass)) {
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
}
	if( strlen(pass)<5 ) {
		write("����ĳ�������Ҫ�����Ԫ���������������룺");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("��������һ���������룬��ȷ����û�Ǵ�");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
	input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
	mapping my;
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("��������������벢��һ�����������趨һ�����룺");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}

		input_to("new_password", 1, ob);
		return;
	}

	write(@TEXT
[2J
[33m����������������������������������������������������������������
[45;33m		���´�������ע���򵼡���������			[2;37;0m
[33m����������������������������������������������������������������[2;37;0m
[35m

һ��������츳��������������ϰ������ϢϢ��ء��������е����������
���������츳��

[36m
	������Ӱ�칥���������������Ĵ�С��
	���ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ����ʦ����������
	���ǣ�Ӱ�������ָ����ٶȼ������������ӵ�������
	����Ӱ���������ܵ�������
[33m
        �������Լ�ָ������һ���ֵ���������� 0 ����ϵͳ���������
        ����������ѡ��(0-4)��
[37m
TEXT);

ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
        input_to("select_gift", ob);
}

void get_gift(string yn, object ob, mapping my, int select)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
                random_gift(my, select);
		printf("\n����[%s]������[%s]������[%s]����[%s]\n",
	                display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]));
                write("��ͬ����һ���츳��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
                input_to("get_gift", ob, my, select);
                return;
	}
        write("\n���ĵ����ʼ���ַ��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
        input_to("get_email", ob, my);
}

void select_gift(string yn, object ob)
{
        int i;
        mapping my = ([]);

        if (!sscanf(yn, "%d", i) || i < 0 || i > 4) {
                write("\n�������������ѡ��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
                input_to("select_gift", ob);
                return;
        }
        if (i) {
                write("\n����������Ҫ����ֵ(10-30)��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
                input_to("set_gift", ob, my, i);
        } else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
        int i;

        if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
                write("\n��ֵ�������������룺");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
                input_to("set_gift", ob, my, select);
                return;
        }
        switch (select) {
                case 1: my["str"] = i; break;
                case 2: my["int"] = i; break;
                case 3: my["con"] = i; break;
                case 4: my["dex"] = i;
        }
        get_gift(" ", ob, my, select);
}

/*	my = ([]);
	random_gift(my);
	printf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]\n",
                my["str"], my["int"], my["con"], my["dex"]);
        write("��������һ���츳��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
        input_to("get_gift", ob, my);
}
void get_gift(string yn, object ob, mapping my)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my);
		printf("\n����[%d]�� ����[%d]�� ����[%d]�� ��[%d]\n",
                      my["str"], my["int"], my["con"], my["dex"]);
                write("��ͬ����һ���츳��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("get_gift", ob, my);
	}
	if (yn[0] == 'y' || yn[0] == 'Y') {
          	write("\n���ĵ����ʼ���ַ��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
        	input_to("get_email", ob, my);
	}
}
*/
void get_email(string email, object ob, mapping my)
{
	object user;
	string id,address;	

	write("\n");
	if (email == "" || strsrch(email, "@") == -1||
		sscanf(email,"%s@%s",id,address)!=2||strsrch(address,".")==-1)
	{
		write("�����ʼ���ַ��Ҫ�� id@address �ĸ�ʽ��\n");
		write("���ĵ����ʼ���ַ��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
}

		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", 1);

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	ob->set("registered", 1);
	user->set("registered", 1);

	write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
	input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user)
{
	write("\n");
	if( gender=="" ) {
		write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "����");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Ů��" );
	else {
		write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
ob->add_temp("input",1);
if (ob->query_temp("input")>120)
{
        write("\n�������ָ�������!!\n");
         destruct(ob);
return;
}
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob, user);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

        if (!ob) return 0;
	if (!ob->query("body")) return 0;
	user = new(ob->query("body"));
	if(!user) {
		write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

init_new_player(object user)
{
	user->set("title", "��ͨ����");
	user->set("birthday", time() );
	user->set("potential", 99);
        user->set("food", (user->query("str")+10)*10);
        user->set("water", (user->query("str")+10)*10);

	user->set("channels", ({ "chat", "rumor", "party", "es" }) );
//	user->set("balance", 1000);
}

		
varargs void enter_world(object ob, object user, int silent)
{
	object cloth, shoe, room, mailbox, gift, fly, login_ob,weapon;
	string startroom;
        object link_ob;
        int card_num;
    int i,temp,maxexp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;        
string wiz_status;
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered", ob->query("registered"));
	user->set_encoding(ob->query_encoding());
//	user->set_temp("big5", ob->query_temp("big5"));
	exec(user, ob);

	write("\nĿǰȨ�ޣ�" + wizhood(user) + "\n");
	user->setup();
	if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
	        user->set("food", user->max_food_capacity());
        	user->set("water", user->max_water_capacity());
	}

	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
	// Use condition to auto save user file
	user->apply_condition("autosave", 1);
	
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(user);
	gift = new("/clone/book/rules");
	gift->move(user);
        if(!user->query("flybag") && (user->query("age") < 19) )
        {
                  fly=new("/clone/misc/fly");
          	    fly->move(user);
        }
//	if (user->query("weapon/type")) {
//		switch((string)user->query("weapon/type"))
//		{
//			case "��":
//			weapon = new("/d/npc/m_weapon/weapon/m_sword");
//			weapon->move(user);
//			break;
//			case "��":
//			weapon = new("/d/npc/m_weapon/weapon/m_blade");
//			weapon->move(user);
//			break;
//			case "��":
//			weapon = new("/d/npc/m_weapon/weapon/m_whip");
//			weapon->move(user);
//			break;
//			case "��":
//			weapon = new("/d/npc/m_weapon/weapon/m_staff");
//			weapon->move(user);
//			break;
//			case "��":
//			weapon = new("/d/npc/m_weapon/weapon/m_club");
//			weapon->move(user);
//			break;
//			default:
//		}
//	}
   //    if(this_player()->quary(age)>==15)
    //    {
      //  if (!user->query("giftcard"))
   //   if(!user->query("giftcard") && (user->query("age") >= 15) )
      //  {
      //          card_num=howmany_card();
      //          set_card(card_num+1);
	//        gift = new("/clone/misc/card");
        //	gift->move(user);
        //        user->set("giftcard", card_num);
       // }
  //      }
//	if (wizhood(user) == "(player)")
	{
		if (user->query("class")=="bonze")
		{
			if (user->query("gender")=="Ů��")
			{
				cloth = new("/clone/cloth/ni-cloth.c");
				shoe = new("/clone/cloth/ni-xie.c");
			}
			else
			{
				cloth = new("/clone/cloth/seng-cloth.c");
				shoe = new("/clone/cloth/seng-xie.c");
			}
		}
		else
		{
			if (user->query("class")=="taoist")
			{
				if ( user->query("gender")=="Ů��")
				{
					cloth = new("/clone/cloth/daogu-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				}
				else
				{
					cloth = new("/clone/cloth/dao-cloth.c");
					shoe = new("/clone/cloth/dao-xie.c");
				}
			}
			else
			{
				if ( user->query("gender")=="Ů��")
				{
					shoe = new("/clone/cloth/female-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/clone/cloth/female1-cloth.c");
						break;
						case 2:
					cloth = new("/clone/cloth/female2-cloth.c");
						break;
						case 3:
					cloth = new("/clone/cloth/female3-cloth.c");
						break;
						case 4:
					cloth = new("/clone/cloth/female4-cloth.c");
						break;
						case 5:
					cloth = new("/clone/cloth/female5-cloth.c");
						break;
						case 6:
					cloth = new("/clone/cloth/female6-cloth.c");
						break;
						case 7:
					cloth = new("/clone/cloth/female7-cloth.c");
						break;
						default:
					cloth = new("/clone/cloth/female8-cloth.c");
					}
				}
				else
				{
					shoe = new("/clone/cloth/male-shoe.c");
					switch (random(8))
					{
						case 1:
					cloth = new("/clone/cloth/male1-cloth.c");
						break;
						case 2:
					cloth = new("/clone/cloth/male2-cloth.c");
						break;
						case 3:
					cloth = new("/clone/cloth/male3-cloth.c");
						break;
						case 4:
					cloth = new("/clone/cloth/male4-cloth.c");
						break;
						case 5:
					cloth = new("/clone/cloth/male5-cloth.c");
						break;
						case 6:
					cloth = new("/clone/cloth/male6-cloth.c");
						break;
						case 7:
					cloth = new("/clone/cloth/male7-cloth.c");
						break;
						default:
					cloth = new("/clone/cloth/male8-cloth.c");
					}
				}
			}
		}
		cloth->move(user);
		cloth->wear();
		shoe->move(user);
		shoe->wear();
	}

	if( !silent ) {
		if (ob->query("registered") == 0) 
			write(read_file(UNREG_MOTD));
		else 
			write(read_file(MOTD));
		if( ob->query("new_mail") ) {
			write(GRN+"\n�����ʲ���������˵�������˼����������ţ�\n\n"+NOR);
			user->set("new_mail", 0);
		}
		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else if( !stringp(startroom = user->query("startroom")) )
			startroom = START_ROOM;

		if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		tell_room(startroom, user->query("name") + "���߽���������硣\n",
			({user}));
	}
        login_ob=new(LOGIN_OB);
        login_ob->set("id",user->query("id"));
        login_ob->restore();
//	login_ob->set("last_on", time());
//	login_ob->set("last_from", query_ip_name(user));
	login_ob->save();

        write(HIW"\n���ϴι��ٺ���II�� " + HIG +ctime(login_ob->query("last_on"))+ NOR + " �� " + HIR +login_ob->query("last_from") + NOR + " ���ӵġ�\n\n"NOR);
        if( login_ob->query("new_mail") )
        {
                write( HIY + "\n�������ţ��쿴��������ɣ�\n\n" + NOR);
                login_ob->set("new_mail", 0);
        }
        destruct(login_ob);

	wiz_status = SECURITY_D->get_status(user);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
{
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)��%s���߽��롣����� " + reclaim_objects() + " ��������\n", user->name(),user->query("id"), query_ip_name(user)) );
}
	UPDATE_D->check_user(user);
        user->set_temp("temp_exp",user->query("combat_exp"));
        user->set_temp("temp_time",time());
        user->set_temp("mud_age",user->query("mud_age"));
         if( user->query("lastChangeSize") != file_size("/doc/help/whatsnew") ) {
		user->set("lastChangeSize", file_size("/doc/help/whatsnew"));
		write(BLINK HIW"\n ����II �����±䶯������ help whatsnew ���鿴��\n\n"NOR);
	}
//if(wizardp(user)) {

if (user->query("str")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("str",60);
}
if (user->query("dex")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("dex",60);
}
if (user->query("int")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("int",60);
}
if (user->query("con")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("con",60);
}
if (user->query("per")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("per",60);
}
if (user->query("kar")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("kar",60);
}
//4ת
if (user->query("str")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("str",70);
}
if (user->query("dex")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("dex",70);
}
if (user->query("int")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("int",70);
}
if (user->query("con")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("con",70);
}
if (user->query("per")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("per",70);
}
if (user->query("kar")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("kar",70);
}

if (user->query("str")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("str",60);
}
if (user->query("dex")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("dex",60);
}
if (user->query("int")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("int",60);
}
if (user->query("con")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("con",60);
}
if (user->query("per")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("per",60);
}
if (user->query("kar")> 60 && !user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("kar",60);
}
//4ת
if (user->query("str")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("str",70);
}
if (user->query("dex")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("dex",70);
}
if (user->query("int")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("int",70);
}
if (user->query("con")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("con",70);
}
if (user->query("per")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("per",70);
}
if (user->query("kar")> 70 && user->query("4zhuan") && !user->query("5zhuan"))
{
           user->set("kar",70);
}
//4ת ,5ת EXP����

if (user->query("4zhuan") || user->query("5zhuan"))
{
maxexp=6000000+(user->query("expmax",1)*500000);
if (user->query("combat_exp",1)> maxexp)
{
user->set("combat_exp",maxexp);
}
write(HIR"Ŀǰ���鳤��:"+maxexp+"!\n"NOR);
}
//�Զ���ת
if ( (user->query("combat_exp",1)>=50000000  && !user->query("zhuanbest") && !user->query("4zhuan") && !user->query("5zhuan")))
{
obj->set("guard/flag",1);
obj->set("tforceok",2);
obj->set("zhuanshen",1);
user->clear_condition();
user->set("betrayer",0);
user->set("title","��ͨ����");
user->set("class","0");
user->set("score",0);
user->set("shen",0);
user->set("max_neili",0);
user->set("max_qi",100);
user->set("max_jing",100);
user->delete("family");
user->delete("party");
user->delete("work/wakuang");
user->delete("work/wunon");
user->delete("work/penlen");
user->delete("work/zhujian");
user->delete("work/zhudao");
user->delete("work/zhubanzi");
user->delete("work/buyu");
user->delete("work/dalie");
user->delete("work/zhaojiu");
user->delete("work/zhujia");
user->delete("work");
user->delete("breakup");
user->delete("last_getzhen");
user->delete("blade_get");
user->delete("szj/failed");
user->delete("jiuyin/shang-failed");
user->delete("jiuyin/xia-failed");
user->delete("zhou/fail");
user->delete("zhou/jieyi");
user->delete("jiuyin/gumu-failed");
user->delete("zhou/failed");
user->set("killbyname",0);
user->set("MKS",0);
user->set("PKS",0);
user->set("zhuanshen",1);
user->set("meili",0);
user->set("dietimes",0);
user->set("normal_die",0);
user->set("weiwang",0);
user->set("mud_age",400000);
user->set("combat_exp",0);        
user->set("eff_qi",user->query("max_qi"));
user->set("qi",user->query("max_qi"));
user->set("eff_jing",user->query("max_jing"));
user->set("jing",user->query("max_jing"));
user->set("jingli",user->query("max_jingli"));
user->set("neili",user->query("max_neili"));
user->set("food",user->max_food_capacity());
user->set("water",user->max_water_capacity());
if (mapp(skill_status = user->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = user->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
user->delete_skill(sname[i]);//ɾ���Լ����й���
}
 

		user->map_skill("unarmed");
		user->map_skill("hammer");
		user->map_skill("blade");
		user->map_skill("stick");
		user->map_skill("staff");
		user->map_skill("club");
		user->map_skill("throwing");
		user->map_skill("parry");
		user->map_skill("dodge");
		user->map_skill("magic");
		user->map_skill("spells");
		user->map_skill("leg");
		user->map_skill("axe");
		user->map_skill("array");
		user->map_skill("whip");	
		user->map_skill("finger");
		user->map_skill("hand");	
		user->map_skill("cuff");	
		user->map_skill("claw");	
		user->map_skill("strike");	

		user->prepare_skill("unarmed");
		user->prepare_skill("hammer");
		user->prepare_skill("blade");
		user->prepare_skill("stick");
		user->prepare_skill("staff");
		user->prepare_skill("club");
		user->prepare_skill("throwing");
		user->prepare_skill("parry");
		user->prepare_skill("dodge");
		user->prepare_skill("magic");
		user->prepare_skill("spells");
		user->prepare_skill("leg");
		user->prepare_skill("axe");
		user->prepare_skill("array");
		user->prepare_skill("whip");	
		user->prepare_skill("finger");
		user->prepare_skill("hand");	
		user->prepare_skill("cuff");	
		user->prepare_skill("claw");	
		user->prepare_skill("strike");	
                user->reset_action();
    if ( user->query("per") < 60)
        {
	user->set("per",user->query("per")+10);
        }
        if ( user->query("str") < 60)
        {
	user->set("str",user->query("str")+10);
        }
        if ( user->query("dex")< 60)
        {
	user->set("dex",user->query("dex")+10);
        }
        if ( user->query("int")< 60)
        {
	user->set("int",user->query("int")+10);
        }
        if ( user->query("con")< 60)
        {
	user->set("con",user->query("con")+10);
        }
        if ( user->query("kar")< 60)
        {
	user->set("kar",user->query("kar")+10);
        }
}


//�Զ���ת
if ( (user->query("combat_exp",1)>=60000000  && user->query("guard/flag") && !user->query("4zhuan") && !user->query("5zhuan")))
{
obj->set("guard/flag",1);
obj->set("tforceok",2);
user->clear_condition();
user->set("betrayer",0);
user->set("title","��ͨ����");
user->set("class","0");
user->set("score",0);
user->set("shen",0);
user->set("max_neili",0);
user->set("max_qi",100);
user->set("max_jing",100);
user->delete("family");
user->delete("party");
user->delete("work/wakuang");
user->delete("work/wunon");
user->delete("work/penlen");
user->delete("work/zhujian");
user->delete("work/zhudao");
user->delete("work/zhubanzi");
user->delete("work/buyu");
user->delete("work/dalie");
user->delete("work/zhaojiu");
user->delete("work/zhujia");
user->delete("work");
user->delete("breakup");
user->delete("last_getzhen");
user->delete("blade_get");
user->delete("szj/failed");
user->delete("jiuyin/shang-failed");
user->delete("jiuyin/xia-failed");
user->delete("zhou/fail");
user->delete("zhou/jieyi");
user->delete("jiuyin/gumu-failed");
user->delete("zhou/failed");
user->set("killbyname",0);
user->set("MKS",0);
user->set("PKS",0);
user->set("zhuanshen",1);
user->set("meili",0);
user->set("dietimes",0);
user->set("normal_die",0);
user->set("weiwang",0);
user->set("mud_age",400000);
user->set("combat_exp",0);        
user->set("eff_qi",user->query("max_qi"));
user->set("qi",user->query("max_qi"));
user->set("eff_jing",user->query("max_jing"));
user->set("jing",user->query("max_jing"));
user->set("jingli",user->query("max_jingli"));
user->set("neili",user->query("max_neili"));
user->set("food",user->max_food_capacity());
user->set("water",user->max_water_capacity());
if (mapp(skill_status = user->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = user->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
user->delete_skill(sname[i]);//ɾ���Լ����й���
}
 
user->set("jiuyin/full",1);
user->set("szj/passed",1);
user->set("zhuanbest",1);
user->delete("last_alert");

		user->map_skill("unarmed");
		user->map_skill("hammer");
		user->map_skill("blade");
		user->map_skill("stick");
		user->map_skill("staff");
		user->map_skill("club");
		user->map_skill("throwing");
		user->map_skill("parry");
		user->map_skill("dodge");
		user->map_skill("magic");
		user->map_skill("spells");
		user->map_skill("leg");
		user->map_skill("axe");
		user->map_skill("array");
		user->map_skill("whip");	
		user->map_skill("finger");
		user->map_skill("hand");	
		user->map_skill("cuff");	
		user->map_skill("claw");	
		user->map_skill("strike");	

		user->prepare_skill("unarmed");
		user->prepare_skill("hammer");
		user->prepare_skill("blade");
		user->prepare_skill("stick");
		user->prepare_skill("staff");
		user->prepare_skill("club");
		user->prepare_skill("throwing");
		user->prepare_skill("parry");
		user->prepare_skill("dodge");
		user->prepare_skill("magic");
		user->prepare_skill("spells");
		user->prepare_skill("leg");
		user->prepare_skill("axe");
		user->prepare_skill("array");
		user->prepare_skill("whip");	
		user->prepare_skill("finger");
		user->prepare_skill("hand");	
		user->prepare_skill("cuff");	
		user->prepare_skill("claw");	
		user->prepare_skill("strike");	
                user->reset_action();
    if ( user->query("per") < 60)
        {
	user->set("per",user->query("per")+10);
        }
        if ( user->query("str") < 60)
        {
	user->set("str",user->query("str")+10);
        }
        if ( user->query("dex")< 60)
        {
	user->set("dex",user->query("dex")+10);
        }
        if ( user->query("int")< 60)
        {
	user->set("int",user->query("int")+10);
        }
        if ( user->query("con")< 60)
        {
	user->set("con",user->query("con")+10);
        }
        if ( user->query("kar")< 60)
        {
	user->set("kar",user->query("kar")+10);
        }
}

//�Զ���ת
if ( (user->query("combat_exp",1)>=100000000 && user->query("zhuanbest")==1 && !user->query("4zhuan")))
{
user->set("tforceok",2);
user->set("double_attack",1);
user->clear_condition();
user->set("betrayer",0);
user->set("title","��ͨ����");
user->set("class","0");
user->set("score",0);
user->set("shen",0);
user->set("max_neili",0);
user->set("max_qi",100);
user->set("max_jing",100);
user->delete("family");
user->delete("party");
user->delete("work/wakuang");
user->delete("work/wunon");
user->delete("work/penlen");
user->delete("work/zhujian");
user->delete("work/zhudao");
user->delete("work/zhubanzi");
user->delete("work/buyu");
user->delete("work/dalie");
user->delete("work/zhaojiu");
user->delete("work/zhujia");
user->delete("work");
user->delete("breakup");
user->delete("last_getzhen");
user->set("killbyname",0);
user->set("MKS",0);
user->set("PKS",0);
user->set("zhuanshen",1);
user->set("meili",0);
user->set("dietimes",0);
user->set("normal_die",0);
user->set("weiwang",0);
user->set("mud_age",400000);
user->set("combat_exp",0);        
user->set("eff_qi",user->query("max_qi"));
user->set("qi",user->query("max_qi"));
user->set("eff_jing",user->query("max_jing"));
user->set("jing",user->query("max_jing"));
user->set("jingli",user->query("max_jingli"));
user->set("neili",user->query("max_neili"));
user->set("food",user->max_food_capacity());
user->set("water",user->max_water_capacity());
if (mapp(skill_status = user->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = user->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
user->delete_skill(sname[i]);//ɾ���Լ����й���
}
		user->map_skill("unarmed");
		user->map_skill("hammer");
		user->map_skill("blade");
		user->map_skill("stick");
		user->map_skill("staff");
		user->map_skill("club");
		user->map_skill("throwing");
		user->map_skill("parry");
		user->map_skill("dodge");
		user->map_skill("magic");
		user->map_skill("spells");
		user->map_skill("leg");
		user->map_skill("axe");
		user->map_skill("array");
		user->map_skill("whip");	
		user->map_skill("finger");
		user->map_skill("hand");	
		user->map_skill("cuff");	
		user->map_skill("claw");	
		user->map_skill("strike");	

		user->prepare_skill("unarmed");
		user->prepare_skill("hammer");
		user->prepare_skill("blade");
		user->prepare_skill("stick");
		user->prepare_skill("staff");
		user->prepare_skill("club");
		user->prepare_skill("throwing");
		user->prepare_skill("parry");
		user->prepare_skill("dodge");
		user->prepare_skill("magic");
		user->prepare_skill("spells");
		user->prepare_skill("leg");
		user->prepare_skill("axe");
		user->prepare_skill("array");
		user->prepare_skill("whip");	
		user->prepare_skill("finger");
		user->prepare_skill("hand");	
		user->prepare_skill("cuff");	
		user->prepare_skill("claw");	
		user->prepare_skill("strike");	
                user->reset_action();

if (!user->query("4zhuan"))
{
  if ( user->query("per") < 70)
        {
	user->set("per",user->query("per")+10);
        }
        if ( user->query("str") < 70)
        {
	user->set("str",user->query("str")+10);
        }
        if ( user->query("dex")< 70)
        {
	user->set("dex",user->query("dex")+10);
        }
        if ( user->query("int")< 70)
        {
	user->set("int",user->query("int")+10);
        }
        if ( user->query("con")< 70)
        {
	user->set("con",user->query("con")+10);
        }
        if ( user->query("kar")< 70)
        {
	user->set("kar",user->query("kar")+10);
        }
if (random(6)==0)
{
user->set("zhuanfinal/6",1);
write(HIY"�����������ʿ��˫�������ɾ���!\n"NOR);
}
else if (random(6)==1)
{
user->set("zhuanfinal/2",1);
write(HIY"�����������Ӱ���١������ɾ���!\n"NOR);
}
else if (random(6)==2)
{
user->set("zhuanfinal/3",1);
write(HIY"�����������ħ���������ɾ���!\n"NOR);
}
else if (random(6)==3)
{
user->set("zhuanfinal/4",1);
write(HIY"������������ǲ��������ɾ���!\n"NOR);
}
else if (random(6)==4)
{
user->set("zhuanfinal/5",1);
write(HIY"�����������Ԫ�󷨡������ɾ���!\n"NOR);
}
else 
{
user->set("zhuanfinal/1",1);
write(HIY"���������Ԫ�������ն�ɾ���!\n"NOR);
}
if (random(2)==0)
{
user->set("zhuanfinal/7",1);
write(HIY"����书������ʮ�����졿!\n"NOR);
}
else
{
user->set("zhuanfinal/8",1);
write(HIY"����书�������񹦡�!\n"NOR);
}
             message("channel:chat",HIW"���������ԡ���"HIW"��˵  "
             +user->query("name")+"("+user->query("id")+")�������ת��\n"NOR,users());

}

user->set("4zhuan",1);
user->save();
write(HIR"�Զ�ת���ɹ�,�����µ�½!\n"NOR);
write(HIR"ת���ɹ�,����������ʿ��ȡת����������!\n"NOR);                

}
//�Զ���ת
if (user->query("4zhuan") && user->query("combat_exp",1)>= 200000000 && !user->query("5zhuan"))
{
user->set("tforceok",2);
user->clear_condition();
user->set("betrayer",0);
user->set("title","��ͨ����");
user->set("class","0");
user->set("score",0);
user->set("shen",0);
user->set("max_neili",0);
user->set("max_qi",100);
user->set("max_jing",100);
user->delete("family");
user->delete("party");
user->delete("work/wakuang");
user->delete("work/wunon");
user->delete("work/penlen");
user->delete("work/zhujian");
user->delete("work/zhudao");
user->delete("work/zhubanzi");
user->delete("work/buyu");
user->delete("work/dalie");
user->delete("work/zhaojiu");
user->delete("work/zhujia");
user->delete("work");
user->delete("breakup");
user->delete("last_getzhen");
user->set("killbyname",0);
user->set("MKS",0);
user->set("PKS",0);
user->set("zhuanshen",1);
user->set("meili",0);
user->set("dietimes",0);
user->set("normal_die",0);
user->set("weiwang",0);
user->set("mud_age",400000);
user->set("combat_exp",0);        
user->set("eff_qi",user->query("max_qi"));
user->set("qi",user->query("max_qi"));
user->set("eff_jing",user->query("max_jing"));
user->set("jing",user->query("max_jing"));
user->set("jingli",user->query("max_jingli"));
user->set("neili",user->query("max_neili"));
user->set("food",user->max_food_capacity());
user->set("water",user->max_water_capacity());
if (mapp(skill_status = user->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = user->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
user->delete_skill(sname[i]);//ɾ���Լ����й���
}
		user->map_skill("unarmed");
		user->map_skill("hammer");
		user->map_skill("blade");
		user->map_skill("stick");
		user->map_skill("staff");
		user->map_skill("club");
		user->map_skill("throwing");
		user->map_skill("parry");
		user->map_skill("dodge");
		user->map_skill("magic");
		user->map_skill("spells");
		user->map_skill("leg");
		user->map_skill("axe");
		user->map_skill("array");
		user->map_skill("whip");	
		user->map_skill("finger");
		user->map_skill("hand");	
		user->map_skill("cuff");	
		user->map_skill("claw");	
		user->map_skill("strike");	

		user->prepare_skill("unarmed");
		user->prepare_skill("hammer");
		user->prepare_skill("blade");
		user->prepare_skill("stick");
		user->prepare_skill("staff");
		user->prepare_skill("club");
		user->prepare_skill("throwing");
		user->prepare_skill("parry");
		user->prepare_skill("dodge");
		user->prepare_skill("magic");
		user->prepare_skill("spells");
		user->prepare_skill("leg");
		user->prepare_skill("axe");
		user->prepare_skill("array");
		user->prepare_skill("whip");	
		user->prepare_skill("finger");
		user->prepare_skill("hand");	
		user->prepare_skill("cuff");	
		user->prepare_skill("claw");	
		user->prepare_skill("strike");	
                user->reset_action();


user->set("5zhuan",1);
  if ( user->query("per") < 80)
        {
	user->set("per",user->query("per")+10);
        }
        if ( user->query("str") < 80)
        {
	user->set("str",user->query("str")+10);
        }
        if ( user->query("dex")< 80)
        {
	user->set("dex",user->query("dex")+10);
        }
        if ( user->query("int")< 80)
        {
	user->set("int",user->query("int")+10);
        }
        if ( user->query("con")< 80)
        {
	user->set("con",user->query("con")+10);
        }
        if ( user->query("kar")< 80)
        {
	user->set("kar",user->query("kar")+10);
        }
user->delete("zhuanfinal");
if (random(4)==0)
{
user->set("zhuanfinal/6",1);
write(HIY"�����������ʿ��˫�������ɾ���!\n"NOR);
user->set("zhuanfinal/5",1);
write(HIY"�����������Ԫ�󷨡������ɾ���!\n"NOR);
user->set("zhuanfinal/1",1);
write(HIY"���������Ԫ�������ն�ɾ���!\n"NOR);
}
else if (random(4)==1)
{
user->set("zhuanfinal/2",1);
write(HIY"�����������Ӱ���١������ɾ���!\n"NOR);
user->set("zhuanfinal/6",1);
write(HIY"�����������ʿ��˫�������ɾ���!\n"NOR);
user->set("zhuanfinal/3",1);
write(HIY"�����������ħ���������ɾ���!\n"NOR);
}
else if (random(4)==2)
{
user->set("zhuanfinal/3",1);
write(HIY"�����������ħ���������ɾ���!\n"NOR);
user->set("zhuanfinal/4",1);
write(HIY"������������ǲ��������ɾ���!\n"NOR);
user->set("zhuanfinal/5",1);
write(HIY"�����������Ԫ�󷨡������ɾ���!\n"NOR);

}
else 
{
user->set("zhuanfinal/4",1);
write(HIY"������������ǲ��������ɾ���!\n"NOR);
user->set("zhuanfinal/1",1);
write(HIY"���������Ԫ�������ն�ɾ���!\n"NOR);
user->set("zhuanfinal/2",1);
write(HIY"�����������Ӱ���١������ɾ���!\n"NOR);
}



user->set("zhuanfinal/7",1);
write(HIY"����书������ʮ�����졿!\n"NOR);
user->set("expmax",1);
user->set("zhuanfinal/8",1);
write(HIY"����书�������񹦡�!\n"NOR);

             message("channel:chat",HIW"���������ԡ���"HIW"��˵  "
             +user->query("name")+"("+user->query("id")+")�������ת��\n"NOR,users());
user->save();
write(HIR"�Զ�ת���ɹ�,�����µ�½!\n"NOR);
write(HIR"ת���ɹ�,����������ʿ��ȡת����������!\n"NOR);                
}

//}
	if(wizardp(user)) {
                if( !ob->query("wizpwd") )
{
     write(HIR"��"WHT"��"HIG"����WIZPWD�趨��Ӧ��WIZ����"WHT"��"NOR"");
}

	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
{
		CHANNEL_D->do_channel( this_object(), "wiz",
			sprintf(NOR "%s" HIY " �� " HIG "%s" HIY " �������ߡ�", user->short(1), query_ip_name(user)) );
}
   	     tell_object(user, BLINK HIG"�ϴ�����ʱ��( " + ctime(ob->query("last_on"))
			+ " )��У�ԡ�\n"NOR);
   	     tell_object(user, BLINK HIG"�ϴ�����IP��ַ( " + ob->query("last_from")
			+ " )��У�ԡ�\n"NOR);

        	if ( wizhood(user)=="(admin)")	{
			if( user->query("wiz_check/FILES") != file_size("/log/FILES") ) 
			{
				user->set("wiz_check/FILES", file_size("/log/FILES"));
				write(HIW"����ʦ�зǷ�д�����������鿴 /log/FILES ��\n"NOR);
			}
			if( user->query("wiz_check/CALL_PLAYER") != file_size("/log/static/CALL_PLAYER") ) 
			{
				user->set("wiz_check/CALL_PLAYER", file_size("/log/static/CALL_PLAYER"));
				write(HIW"����ʦ��ʹ�ù�call�������鿴 /log/static/CALL_PLAYER ��\n"NOR);
			}
			if( user->query("wiz_check/log") != file_size("/log/log") ) 
			{
				user->set("wiz_check/log", file_size("/log/log"));
				write(HIW"�����ļ�update���������鿴 /log/log ��\n"NOR);
			}
			if( user->query("wiz_check/PURGE_PLAYER") != file_size("/log/static/PURGE") ) 
			{
				user->set("wiz_check/PURGE_PLAYER", file_size("/log/static/PURGE"));
				write(HIW"����ʹ�ù�PURGE���������鿴 /log/static/PURGE ��\n"NOR);
			}
			if( user->query("wiz_check/promotion_PLAYER") != file_size("/log/static/PURGE") ) 
			{
				user->set("wiz_check/promotion_PLAYER", file_size("/log/static/promotion"));
				write(HIW"����ʹ�ù�Ȩ����������鿴 /log/static/promotion ��\n"NOR);
			}
		}
		return;
	} 
	else
        {
                if ( user->query("mud_age") <= 0)
                       {
		user->set("last_on", time());
		user->set("last_from", query_ip_name(user));
		user->save();
             message("channel:chat",HIW"������ͨ�桿��"HIW"���һ�ӭ�����  "
             +user->query("name")+"("+user->query("id")+")����"+MUD_NAME+"�����λ�����գ�\n"NOR,users());
                        } 
                        else
                        {
             message("channel:chat",HIW"������ͨ�桿��"
             +user->query("name")+"("+user->query("id")+")�ٴ������˺���II����ӭ�������\n"NOR,users());
   	     tell_object(user, BLINK HIG"�ϴ�����ʱ��( " + ctime(ob->query("last_on"))
			+ " )��У�ԡ�\n"NOR);
   	     tell_object(user, BLINK HIG"�ϴ�����IP��ַ( " + ob->query("last_from")
			+ " )��У�ԡ�\n"NOR);

             user->delete("vendetta/authority");
//           user->set("food",ob->max_food_capacity());
//           user->set("water",ob->max_water_capacity());
if (user->query("food")<100)
{
           user->add("food",50);
}
if (user->query("water")<100)
{
           user->add("water",50);
}
//             message("channel:chat",HIW"������ͨ�桿��"
//             +user->query("name")+"("+user->query("id")+")����save����,������10.24��save�ָ�,��ҵ�gc,��yaoshu�ɵ�һ���Ĳ�����\n"NOR,users());
                        }

	}
	return;
}

varargs void reconnect(object ob, object user, int silent)
{
string temps;
	object userp;
	int time_rl;
string wiz_status;
        
        userp = find_body(user->query("id"));
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	ob->set_encoding(ob->query_encoding());
	ob->set("last_on", time());
	ob->save();
	exec(user, ob);
//        time_rl = time() - user->query("last_on");
//	if (time_rl >= 0 && time_rl <= 10)
//	{
//		temps = sprintf("����ϴ��˳��� %d ��?\n", time_rl);
//		write(temps);
//			write("�Բ���Ϊ�˽���ϵͳ���ɣ����Ժ���login����л���ĺ�����\n");
//	                destruct(userp);
//	                return 0;
//	}
	user->set("last_on", time());
	user->reconnect();
	if( !silent ) {
		tell_room(environment(user), user->query("name") + "�������߻ص�������硣\n",
		({user}));
	}
	wiz_status = SECURITY_D->get_status(user);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
{
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s��%s�������߽��롣", user->query("name"), query_ip_name(user)) );
}
	UPDATE_D->check_user(user);

}

int check_legal_id(string id)
{
	int i;

	i = strlen(id);
	

	if( id=="all"){
		write("�Բ��𣬲���ʹ��all��Ϊid��\n");
	return 0;
	}
	if( id=="corpse"){
		write("�Բ��𣬲���ʹ��corpse��Ϊid��\n");
	return 0;
	}
	if( id=="admin"){
		write("�Բ��𣬲���ʹ��admin��Ϊid��\n");
	return 0;
	}
	if( id=="guest"){
		write("�Բ��𣬲���ʹ��guest��Ϊid��\n");
	return 0;
	}
	if( id=="root"){
		write("�Բ��𣬲���ʹ��root��Ϊid��\n");
	return 0;
	}
	if( id=="gold"){
		write("�Բ��𣬲���ʹ��gold��Ϊid��\n");
	return 0;
	}
	if( id=="bing"){
		write("�Բ��𣬲���ʹ��bing��Ϊid��\n");
	return 0;
	}
	if( id=="none"){
		write("�Բ��𣬲���ʹ��none��Ϊid��\n");
	return 0;
	}
	if( id=="silver"){
		write("�Բ��𣬲���ʹ��silver��Ϊid��\n");
	return 0;
	}
	if( strsrch(id, "none")>=0){
		write("�Բ��𣬲���ʹ��none��Ϊid��\n");
	return 0;
	}
	if( strsrch(id, "robber")>=0){
		write("�Բ��𣬲���ʹ��robber��Ϊid��\n");
	return 0;
	}
	
	if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
		write("�Բ������Ӣ�����ֱ����� 3 �� 12 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
			return 0;
		}

	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	

	if( (strlen(name) < 4) || (strlen(name) > 10 ) ) {
		write("�Բ�������������ֱ����� 2 �� 5 �������֡�\n");
		return 0;
	}

	while(i--) {
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
//		if( name[i]<=' ' ) {
			write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
//		if( i%2==0 && !is_chinese(name[i..<0]) ) {
//			write("�Բ��������á����ġ�ȡ���֡�\n");
//			return 0;

		if( (strsrch(name, "��") >= 0) ||
		    (strsrch(name, "��") >= 0)) {
			write("�Բ�������������ֲ������������ĵ��֡�\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("�Բ����������ֻ���������˵����š�\n");
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&	getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
// add for ten top. 
int set_madlock(int setmark)
{
	if( wiz_level(this_player(1)) < wiz_level("(arch)") )
		return 0;
	if( setmark == 1 ) mad_lock = 1;
	else mad_lock = 0;
	return 1;
}

int get_madlock()
{
	return mad_lock;
}
int howmuch_money(object ob)
{
	int total;
	int total2;
	object gold, silver, coin;

	total = 0;
	total2 = 0;

	gold = present("gold_money",ob);
	silver = present("silver_money",ob);
	coin = present("coin_money",ob);

	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	total2 = (int)ob->query("balance");
	if (!total2 || total2 < 0) {
		ob->set("balance", 0);
	}
	total=total+total2;
	return total;
}
// 10
int check_legal_password(object ob,string pass)
{
        int i;
	int bigletter=0;
	int smlletter=0;
	int number=0;
	string id;
        i = strlen(pass);
        if( strlen(pass) <= 5)   {
                write(WHT"�Բ����������������������ַ���\n\n");
                return 0;
        }
	id= ob->query("id");	
	if ( strsrch(id, pass) != -1 || strsrch(pass,id) != -1)
	{
	write(WHT"�Բ��������������Ӣ������̫���ˡ�\n"NOR);
                return 0;
        }

        while(i--) {
                if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
		if( pass[i]<='z' && pass[i] >='a' ) smlletter++;

        }
	if( bigletter == 0 || smlletter == 0 || 
	bigletter+smlletter == strlen(pass))
{
        write(WHT"����������������д" + RED"��" + WHT"СдӢ����ĸ"
		+ RED"��" + WHT"����������ţ����֣���㣩��\n"NOR);
	return 0;
}
        return 1;
}
