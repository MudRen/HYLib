//help.c,���в���bbs�ͳ�ǿ���ļ����ӹ���
//created by hyee������Host��helpϵͳ�ܵ�����
//��ͬ��mudlib��ע������define��Ŀ¼��valid_write()
#include <mudlib.h>
#include <ansi.h>
#include <login.h>
#include "/doc/help.h"
/*���������ĵ�������Ŀ¼*/
#define DIR "/doc/help/"
/*���屾�ļ��Ĵ浵���ڵ�Ŀ¼*/
#define POST DIR"post.o"
/*�������register�ļ�����Ŀ¼*/
#define REGISTER DIR+"register/"
/*����������԰�����Ŀ¼*/
#define BOARD "/clone/board/"
/*board�������ļ�*/
#define BOARDCENTER BOARD+"center.h"
/*�����ܶԱ�ϵͳ�����޸ĵ���ʦ�ȼ�*/
#define WIZLEVEL "(arch)"
inherit ITEM;
inherit F_SAVE;
varargs void display(object ob);
void auto_load();
void view_main();
void view_main_1();
void m_display();
void u_display();
void view6();
void view7(string arg);
void do_discard(object ob);
void do_more(string arg,string *text,int line,object ob);
void getname1(string arg);
void getname3(string arg);
void getname2(string str,string arg);
void delfile(string arg);
private void confirm_main_choice(string arg);
private void confirm_p_choice(string arg,object ob);
private void confirm_k_choice(string arg);
private void confirm_l_choice(string arg);
private void confirm_choice(string arg);
private void a(string arg, string register);
private void b(string arg, string register);
private void c(string arg, string register);
private void d(string arg, string register);
private void e(string arg, string register);
private void f(string arg, string register);
private void g(string arg, string register);
private void y(string arg, string register);
private void confirm_u_choice(string arg);
string *default_search = DEFAULT_SEARCH_PATHS;
string age_string(int time);
int do_post(string arg,object ob);
int wizlist();
int message();
int message1();
string query_save_file()
{
	return POST;
}
void create()
{
	set("name","��������");
	mkdir(DIR);
	mkdir(REGISTER);
	restore();
	rm(BOARDCENTER);
	save();
}
int start_help(string msg,object ob)
{
	if(!ob) ob=this_object();
        do_more("d",explode(msg, "\n"),0,ob);
}
int main(object me, string arg)
{
        int i;
	string file, *search;
	
       	if( !arg ) {
                me->set_temp("help",1);
                m_display();
                write(YEL"�����ڵĴ��㣺"NOR);
                input_to((:confirm_main_choice:),this_player());
                return 1; 
        }
          	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
		return file->help(me);
	}
       	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}
	sscanf(arg, "%s()", arg);
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
  	  }
	return notify_fail("û��������������˵���ļ���\n");
}
void view_main()
{
     object me;
     string name,select;
     me = this_player();
     select = me->query_temp("select");
     write(CLR"\n");
     if(select== "main") name = "�û�ָ��";
     else if( select== "intro") name = "��Ϸ�ſ�";
     else if( select== "depart") name = "���ɽ���";
     else if( select== "map") name = "����ָ��";
     else if( select== "user") name = "�����趨��";
     else if( select== "board") name = "��Ҫ������";
     else if( select== "post") name = "��������";
     else if( select== "leaveword") name= "�������԰�";
     else if( select== "culture" ) name="īԵ";
     else if( select== "other" ) name="����";
     else if( select== "xyz" ) name="ϵͳ�趨��";     
     write(HIY"����ѡ��"HIW"                     ��"+MUDLIB_NAME+"��                  "HIY"ѡ��["+select+"]\n"NOR);     
     write("Ŀǰѡ��[ "+name+" ]\n");
     write(HIR"�������������������������������� ����� ��������������������������������\n"NOR);
     auto_load();
     write(HIR"������������������������������������������������������������������������\n"NOR);  
     write("\n");
}
void view_main_1()
{
     int i,ppl_cnt;
     object *usr;
     usr = users();
     ppl_cnt=0;
     for(i=0; i<sizeof(usr); i++)
       {
          ppl_cnt++;
       }    
     write(YEL"_.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*\n"NOR);       
     write(HIY"TIME:["HIC""+ctime(time())+""HIY"]    ONLINE/PLAYER:["HIC""+ppl_cnt+""HIY"]    USER:["HIC""+wizhood(this_player())+""HIY"]\n"NOR,); 
}
void view_main_k()
{
     object me;
     string name,select;
     me = this_player();
     select = me->query_temp("select");
     write(CLR"\n");
     if(select== "main") name = "�û�ָ��";
     else if( select== "intro") name = "��Ϸ�ſ�";
     else if( select== "depart") name = "���ɽ���";
     else if( select== "map") name = "����ָ��";
     else if( select== "user") name = "�����趨��";
     else if( select== "board") name = "��Ҫ������";
     else if( select== "post") name = "��������";
     write(HIY"����ѡ��"HIW"                     ��"+MUD_NAME+"��                  "HIY"ѡ��["+select+"]\n"NOR);     
     write("Ŀǰѡ��[ "+name+" ]\n");
     write(HIR"�������������������������������� ����� ��������������������������������\n"NOR);    
}
void m_display()
 {
     this_player()->set_temp("select","main");
     view_main();
     write("                        "HIY"(I)"NOR"ntro  ����  ��Ϸ�ſ�  ��\n");
     write("                        "HIY"(D)"NOR"epart ����  ���ɽ���  ��\n");
     write("                        "HIY"(M)"NOR"ap    ����  ����ָ��  ��\n");
     write("                        "HIY"(U)"NOR"ser     �� �����趨�� ��\n");
     write("		        "HIY"(C)"NOR"ulture  ��   ī  Ե   ��\n");
     write("                        "HIY"(B)"NOR"board ���� ��Ҫ������ ��\n");
     write("                        "HIY"(L)"NOR"eaveword�� �������԰� ��\n");
     write("     		        "HIY"(O)"NOR"ther    ��    �� ��   ��\n");	
     write("                        "HIY"(X)"NOR"yz      �� ϵͳ�趨�� ��\n"); 
     write("	                "HIY"(P)"NOR"BBS     ��  ��������  ��\n");   	
     write("                        "HIY"(G)"NOR"oodbye�� �ٱ𡾰������������������\n");
     view_main_1();
}

void auto_load()
{
    if(random(10) > 5)
    wizlist();
    else if( random(20) >  10)
    message(); 
    else 
    message1();
}
int message1()
{
       object me;
      int i;
      me = this_player();
      i = me->query("MKS")+me->query("PKS");
      write(HIC"      "+me->name()+"��, ������Ѿ����������"+age_string((int)me->query("mud_age"))+"��!!\n");
      write(HIW"      �����ڱ���͵ķַ�������, ���Ѿ��ۻ���"+chinese_number(me->query("combat_exp"))+"�㾭��ֵ\n");
      write(HIW"      ������"+chinese_number(i)+"������\n");
      write(HIC"                    �����!! \n");
}
string age_string(int time)
{
        int month, day, hour, min, sec;
        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "��":"") + (day?day + "��":"") +
        (hour?hour + "Сʱ":"") + min + "��";
}
int message()
{
 write(HIR"   ��    �� �� ��  ����      ��     ��     ����   �����   ����\n"NOR);
 write(HIB" ������   ������    ������   ����     ������   ������     ��      ����\n"NOR);
 write(HIY"  ����    ��  ��   ��         �� ��    ����     �� ��   ��  ��    ������\n"NOR);
 write(HIC""+this_player()->name()+",ǧ�������̫��ඣ�ע��������塣������Ӥ֮��Ȼ����������֮������\n"NOR);
}
int wizlist()
{
        string *wizlist,*list,wiz_name,wiz_level,str,str1,str2,str3,str4;
        int i,s1,s2,s3,s4;
        str1="",str2="",str3="",str4="";
        s1=0;s2=0;s3=0;s4=0;

        list = sort_array(SECURITY_D->query_wizlist(),1);
        wizlist = explode(read_file(WIZLIST), "\n");
        for(i=0; i<sizeof(wizlist); i++)  {
        sscanf(wizlist[i], "%s %s", wiz_name, wiz_level);
                switch(wiz_level)
                {
                        case "(apprentice)":
                                str1 += (s1?"\t":"")+wiz_name;
                                s1++;
                                if(s1%6==0) str1 += "\n \t\t ";
                                break;
                        case "(wizard)":
                                str2 += (s2?"\t":"")+wiz_name;
                                s2++;
                                if(s2%6==0) str2 += "\n \t\t ";
                                break;
                        case "(arch)":
                                str3 += (s3?"\t":"")+wiz_name;
                                s3++;
                                if(s3%6==0) str3 += "\n \t\t ";
                                break;
                        case "(admin)":
                                str4 += (s4?"\t":"")+wiz_name;
                                s4++;
                                if(s4%6==0) str4 += "\n \t\t";
                                break;

                }
        }
        write(HIR"   �� ɢ �� ��: "NOR+str1+"\n");
        write(HIY"   �� �� �� ��: "NOR+str2+"\n");
        write(HIG"   �� �� �� ��: "NOR+str3+"\n");
        write(HIW"   �� �� �� ��: "NOR+str4+"\n");
}

private void confirm_main_choice(string arg)
{	
	this_player()->delete_temp("memer");
 	switch(arg[0]){
 		case 'p':
    	    	this_player()->set_temp("select","post");
    	    	this_player()->set_temp("memer","post/page");
    	     	display();             	
             	return ; 
             	break;
             	case 'd':
             	this_player()->set_temp("select","depart");
             	display();   	         
             	return;
             	break;
             	case 'i':
             	this_player()->set_temp("select","intro");
             	display();   	         
             	return;
             	break;
             	case 'm':
             	this_player()->set_temp("select","map");
             	display();   	         
             	return;
             	break;
             	case 'o':
             	this_player()->set_temp("select","other");
             	display();  
             	return;
             	break;
             	case 'b':
             	this_player()->set_temp("select","board");
             	display();
             	return;
             	break;
             	case 'c':
             	this_player()->set_temp("select","culture");
             	display();
             	return;  
             	break;
             	case 'x':
             	this_player()->set_temp("select","xyz");
             	display();
             	return;
             	break;
             	case 'l':
             	this_player()->set_temp("select","leaveword");
             	display();
             	return;
             	break;
             	case 'u':
             	this_player()->set_temp("select","user");
             	u_display();
             	write(YEL"\r����������ѡ��:"NOR);
             	input_to((:confirm_u_choice:),this_player());
             	return;             
             	break;
    		case 'g':
             	this_player()->delete_temp("select");
             	this_player()->delete_temp("help");
             	return;
        }        
        m_display();
        write(YEL"����������ѡ��:"NOR);
        input_to((:confirm_main_choice:),this_player());                  
  	return;
}
/*���԰����*/
void view1()
{
	write(HIC"  (P)"NOR"���� "HIC"(D)"NOR"ɾ�� "HIC"(U)"NOR"�Ϸ� "HIC"(O)"NOR"�·�" 
	HIC" (B)"NOR"���� "HIC"(E)"NOR"���� "HIC"(K)"NOR"���� "HIC"(J)"NOR"����\n");
	write(HIR"������������������������������������������������������������������������\n"NOR);  
	return;
}
string view_msg(int flag,object ob)
{
	object me=this_player();
	string memer=me->query_temp("memer");
	mapping *notes=ob->query("notes");	
	string file;
	int i,k,b,f;
	file="";	
	k=sizeof(notes)-1;		
	if(!sizeof(notes)) return "û���κ����ԡ�\n";
	if(flag<0) flag=k;
	if(flag>k) flag=0;
	me->set(memer,flag);
	b=flag-7;f=flag+7;
	if(b<0) {f=f-b;b=0;}
	if(f>k) {b=b-f+k;f=k;}
	if(b<0) b=0;
	if(f>k) f=k;	
	f++;		
	for(i=b;i<f;i++)
	file += sprintf("%s["NOR+HIW +BRED"%3d"NOR"%s]  %-30s %12s (%s)(%s)\n"NOR,
			(i==flag)?BRED +HIW:"",
			i+1, (i==flag)?BRED +HIW:"",notes[i]["title"], notes[i]["author"],
			notes[i]["authorid"],ctime(notes[i]["time"])[0..15] );
	return file;		
}

private void confirm_p_choice(string arg,object ob)
{
	object me=this_player();
	int k=atoi(arg);
	int p,num;
	string memer=me->query_temp("memer");	
	mapping *notes;		     	
	if(k>0) 
	{
		me->set(memer,k-1);
     		display(ob);
     	}     	
     	switch(arg)
     	{
     		case "p":
     		do_post(0,ob);
     		return;
     		break;
     		case "b":
     		main(this_player(),0);
     		return;     		
     		case "j":     		
     		me->set(memer,me->query(memer)+1);
     		display(ob);
     		return;
     		break;
     		case "k":
     		me->set(memer,me->query(memer)-1);
     		display(ob);
     		return;
     		break;
     		case "u":
     		me->set(memer,me->query(memer)-15);
     		display(ob);
     		return;
     		break;
     		case "o":
     		me->set(memer,me->query(memer)+15);
     		display(ob);
     		return;
     		break;     		
     		case "d":
     		do_discard(ob);
     		display(ob);     	
     		return;
     		break;      		
     		break;
     		case "e":
     		num=this_player()->query(memer);
		notes=ob->query("notes");
		if( !pointerp(notes) || !sizeof(notes) )
		{
			write("���԰���Ŀǰû���κ����ԡ�\n");
			display(ob);
			return;
		}	
		if(  num+1 > sizeof(notes) )
		{
			write("û���������ԡ�\n");
			display(ob);
			return;
		}			
		printf("["BBLU"%3d"NOR"] %-30s %s(%s)(%s)\n",
		num + 1, notes[num]["title"], notes[num]["author"], notes[num]["authorid"],
		ctime(notes[num]["time"])[0..9]);
     		start_help(notes[num]["msg"],ob);
     		return;
     		break;
     	}
     	display(ob);     	
     	return; 
}
int edi(function callback)
{
        write(HIC"    ��д������'.'��ȡ�������� '^q'��ʹ���ڽ��б༭���� '^e'��\n"NOR);
        write(HIG"������������������������������������������������������������������\n��"NOR);
        input_to("input_lines", "", callback);
        return 1;
}

void input_lines(string line, string text, function callback)
{
        if( line=="." ) {
        	write(HIG"������������������������������������������������������������������\n"NOR);
                (*callback)(text);
                return;
        } else if( line=="^q" ) {
                write("����ȡ����\n");
                main(this_player(),0);
        } else if( line=="^e" ) {
	} else  {
		line=replace_string(line,";",";\n");
                text += line + "\n";
        }
        write(HIG"��"NOR);        
        input_to("input_lines", text, callback);
}
void done_post(mapping note,object ob,string text)
{
	mapping *notes;
	if(strlen(text)<20)
	{
		write(HIC"���ı���Ϊ�ǹ�ˮ���£����跢��\n"NOR);
		display(ob);	
		return;
	}	
	text=replace_string(text,";","\n");
	note["msg"] = text;
	notes = ob->query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });	
	ob->set("notes", notes);
	write("������ϡ�\n");
	ob->save();
	display(ob);	
	return;
}	
int do_post(string arg,object ob)
{
	mapping note;
	if(!arg||arg=="")
	{
		write(HIY"\n��ָ��һ������:"NOR"(��Q����ȡ��)");
		input_to((:do_post:),ob);
		return 1;
	}
	if(arg=="q"||arg=="Q")
	{
		display(ob);		
		return 1;
	}	
	note = allocate_mapping(5);
	note["title"] = arg;
	note["author"] = this_player()->name(1);
	note["authorid"] =this_player()->query("id");
	note["time"] = time();
	edi((: done_post,note,ob:));		
     	return 1;
}
void do_discard(object ob)
{
	mapping note,*notes;	
	int num;
	string memer=this_player()->query_temp("memer");
	num=this_player()->query(memer)+1;
	notes = ob->query("notes");
	
	if( !arrayp(notes) ||!sizeof(notes)||num < 1 || num > sizeof(notes))
	{
		write("û���������ԡ�\n");
		return;
	}
	num--;
	if( notes[num]["authorid"] != (string) this_player(1)->query("id")
        &&      wiz_level(this_player(1)) < wiz_level(WIZLEVEL))
	{
		write("������Բ�����д�ġ�\n");
		return;
	}	
	if(num == 0)
		notes = notes[num+1..sizeof(notes)-1];
	else
		notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	ob->set("notes", notes);
	ob->save();
	write("ɾ���� " + (num+1) + " ������....Ok��\n");
	return;
}
varargs void view2(int line,string *text,object ob,int i)
{	
	int w=line;
	if(i) w=w+17;
	write( "������������������������������������������������������������������������������\n"NOR);  
     	printf("�� ������:"HIR+"%5d "NOR+"��������:"HIR+"%5d "+HIC"(T"NOR"x"HIC")"NOR"����x�� "HIC"(U)"NOR"���� "
     	HIC"(D)"NOR"���� "HIC"(R)"NOR"���� "HIC"(B)"NOR"����  ��\n",sizeof(text),w);
     	write( "������������������������������������������������������������������������������\n"NOR);  
     	write(YEL"����ѡ��"NOR);     	
     	input_to((:do_more:),text,line,ob);
     	return;
}
void do_more(string cmd,string *text,int line,object ob)
{
        int i,j,num;
        mapping *notes;
	string t=this_player()->query_temp("select");	
	string memer=this_player()->query_temp("memer");
	if(!ob) ob=this_object();
	if(cmd[0]=='t')
	{
		j=atoi(cmd[1..<0]);
		if(j)
		{
			line=j;
			cmd="u";
		}
	}		        
	else if(j=atoi(cmd))
	{
		line=j;
		cmd="u";
	}
	switch(cmd) {
        case "d":       
        	if(line+17>=sizeof(text)) line=sizeof(text)-17;
        	if(line<0) line=0; 	
        	if(line<sizeof(text)) 
        	{	        	
        		write("������������������������������������������������������������������������������\n");
               		for(i=line + 17; line<sizeof(text) && line<i; line++)
                   	write("��"+text[line] + "\n");
               		if( line>=sizeof(text) ) 
                   	write("������������������������������ ȫ  ��  �� ������������������������������������\n");			 
                }
                view2(line,text,ob);		                                    
                return;
                break; 
        case "u":
        	if(line>=sizeof(text)) line=sizeof(text);
               	line = line - 17;
               	if(line<0) line=0;
               	write("������������������������������������������������������������������������������\n");
               	for(i=line + 17;line<sizeof(text)&&line < i;line++)
               	write("��"+text[line]+"\n");
               	if( line>=sizeof(text) ) 
                write("������������������������������ ȫ  ��  �� ������������������������������������\n");			 
               	view2(line-17,text,ob,1);               	
               	return;
               	break;
        case "b":        	
               	return display(ob);               	
               	break;
        case "r":
        	if(t=="post")
        	{
        		num=this_player()->query(memer);
        		notes=ob->query("notes");
        		do_post("[����]"+notes[num]["title"],ob);
        	}        	
        	return;                       
        }	
        view2(line,text,ob);       
        return;
}
int register()
{
   	object me;
   	me = this_player();
   	if(!me->query("register")) {   		
        	write(CLR"\n");
         	write(HIW"��ʹ�����趨��        "HIY"��"+MUD_NAME+"ע�ᵥ��\n"NOR);
         	write("\n");
         	write(YEL"Ŀǰѡ��\n\n"NOR);
         	write(HIW"    ���Ĵ���     : "NOR);
         	input_to((:a:),this_player());
         	return 1;
        }
    	write("���Ѿ���д��ע�ᵥ��\n");
     	input_to("confirm_u_choice",this_player());
     	return 1;
}
private void a(string arg, string register)
{
   	register = "����     : "+arg+"\n";
   	this_player()->add_temp("register",register);
   	write(HIW"    �����ǳ�     : "NOR);
   	input_to((:b:),this_player(),register);
}
private void b(string arg, string register)
{
   	register = "�ǳ�     : "+arg+"\n";
   	this_player()->add_temp("register",register);
   	write(HIW"    ��ʵ����     : "NOR);
   	input_to((:c:),this_player());
}
private void c(string arg, string register)
{
   	register = "����     : "+arg+"\n";
   	this_player()->add_temp("register",register);
   	write(HIW"    ��ϵ��ַ     : "NOR);
   	input_to((:d:),this_player());
}
private void d(string arg, string register)
{
   	register = "��ϵ��ַ     : "+arg+"\n";
   	this_player()->add_temp("register",register);
   	write(HIW"    ������λ/ѧУ: "NOR);
   	input_to((:e:),this_player());
}
private void e(string arg, string register)
{
   	register = "������λ/ѧУ: "+arg+"\n";
   	this_player()->add_temp("register",register);
   	write(HIW"    ��������: "NOR);
   	input_to((:f:),this_player());
}
private void f(string arg, string register)
{
   	register = "��������: "+arg+"\n";
   	this_player()->add_temp("register",register);
   	write(HIW"    ��ϵ�绰: "NOR);
   	input_to((:g:),this_player());
}
private void g(string arg, string register)
{
   	register = "��ϵ�绰: "+arg+"\n";
   	this_player()->add_temp("register",register);
   	write(HIW"\n\n\n\n\n\n���������Ƿ���ȷ(Y/N)��(Q)ȡ��ע�� [N]:"NOR);
   	input_to((:y:),this_player());
}
private void y(string arg, string register) 
{
   	string table;
   	if(arg=="") {
   		this_player()->delete_temp("register");
   		register();
   		return ;
   	}	
	switch(arg[0]){
   	case 'n':
           	this_player()->delete_temp("register");
           	register();
           	return ;
           	break;
   	case 'y': 
           	this_player()->set("register",1);
           	table =  this_player()->query_temp("register");
           	this_player()->delete_temp("register");
           	write_file(REGISTER+this_player()->query("id"),table,1);
           	write("������һ����ȷ��\n"); 
           	input_to("confirm_u_choice",this_player());
           	return;
           	break;
   	case 'q':
           	this_player()->delete_temp("register");
           	u_display();
           	write(YEL"\r����������ѡ��:"NOR);
           	input_to((:confirm_u_choice:),this_player());
           	return ;
           	break;
   	default:
           	this_player()->delete_temp("register");
           	register();
           	return ;
           	break;
     	}
  	return ;
}
int pager()
{
    	object me;
    	me = this_player();
    	if(me->query_temp("call_on")) {
    		write("�� Pager Ƶ��\n");
    		me->delete_temp("call_on");
    	} else {
   		write("�ر� Pager Ƶ��\n");
   		me->set_temp("call_on",1);
   	}
  	return 1;
}
int cloak()
{
   	object me;
   	me = this_player();
   	if(!wizardp(me))
    	{
           	u_display();
           	write(YEL"\r����������ѡ��:"NOR);
           	input_to((:confirm_u_choice:),this_player());
           	return 1;
   	} 
   	if(me->query("env/invisibility")) 
   	{
    		write("��Ҫ���ֽ���...\n");
    		me->delete("env/invisibility");
    	} else {
    		write("�����������������ˡ�\n");
    		me->set("env/invisibility",5);
   	}
  	return 1;
}
int lock()
{
    	object me,ob;
    	me = this_player();
    	ob = me->query_temp("link_ob"); 
    	write(HIW"�� ���������룬�Խ��өĻ������"NOR);
    	input_to("get_old_pass", 1, ob);
    	return 1;
}
private void confirm_u_choice(string arg)
{
 	this_player()->set_temp("help_u",1);
 	if(arg=="") {
     		u_display();
     		write(YEL "\r��������������ѡ��:"NOR);
     		input_to((:confirm_u_choice:),this_player());
     		return ; 
     	}
 	switch(arg[0]){
    	case 'r':
            	register();
            	return ;
            	break;
    	case 'p':
            	pager();
            	write(YEL "\r��������������ѡ��:"NOR);
            	input_to((:confirm_u_choice:),this_player());
             	return ;
             	break;
    	case 'c':
            	cloak();
            	write(YEL "\r��������������ѡ��:"NOR);
            	input_to((:confirm_u_choice:),this_player());
            	return ;
            	break;
    	case 'l':
            	lock();
            	return ;
            	break;
    	case 'f':
    	case 'h':
    	case 'g':
             	m_display();
             	write(YEL "\r����������ѡ��:"NOR);
             	this_player()->delete_temp("help_u");
             	input_to((:confirm_main_choice:),this_player());
             	return ;
             	break;
    	default:
           	u_display();
           	write(YEL"\r����������ѡ��:"NOR);
           	input_to((:confirm_u_choice:),this_player());
           	return ;
        }
  	return;
}
void u_display()
{
      	view_main();
      	if (wizardp(this_player()))
      	write("                       "HIC"(��)"NOR"loak       ������\n");
      	write("                       "HIC"(��)"NOR"ockScreen  ����өĻ\n");
      	write("                       "HIC"(��)"NOR"egister    ��д��ע�����뵥��\n");
      	write("                       "HIC"(��)"NOR"ager       �л�������\n");
      	write("                       "HIC"(��)"NOR"return     �������˵�\n");
      	view_main_1();
}
void get_old_pass(string pass, object ob)
{
        string old_pass;
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
        	lock();
        	return ; 
        }
        u_display();
        write(YEL"\r����������ѡ��:"NOR);
        input_to((:confirm_u_choice:),this_player());
        return ;
} 
string find_file()
{
 	string str=this_player()->query_temp("select"); 	
 	str=DIR+str+".h"; 	
 	return str;
}
void getname1(string arg)
{	
	int k;
	if(!arg||arg=="")
	{
		write(HIC"�������������ƣ�"NOR);
		input_to("getname1");
		return;
	}
	if(arg=="q"||arg=="Q")
	{
		display();
		return;
	}		
	k=strlen(arg);
	if(k<2||k>16)
	{
		write(HIG"������������������2��16����Ԫ֮�䣡\n"NOR);
		write(HIC"�������������ƣ�"NOR);
		input_to("getname1");
		return;
	}
	write(HIG"���������ӵ�����"NOR);
	input_to("getname2",arg);
	return;
}
void getname2(string str,string arg)
{
	string file=read_file(find_file()),msg,t;
	string *text,*w;
	if(str=="q"||str=="Q")
	{
		display();
		return;
	}	
	if(file_size(str)<0)
	{
		write(HIY"û�����������\n"NOR);
		write(HIG"���������ӵ�����"NOR);
		input_to("getname2",arg);
		return;
	}
	if(!file) file="";	
	file+=arg+"==@=="+str+"\n";
	text=explode(file,"\n");
	file="";
	while(sizeof(text))
	{
		msg=text[0];	
		text-=({msg});		
		w=explode(msg,"==@==");
		t=replace_string(find_file(),".h","");
		t=t+"/"+w[1]+".h";
		if(file_size(w[1])<0&&file_size(t)<0)
		continue;
		file+=msg+"\n";
	}
	write_file(find_file(),file,1);
	write("OK!\n");
	display();
	return;
}
void view7(string arg)
{
	int k;
	string file=read_file(find_file()),*text;
	if(!arg)
	{
		write(HIC"��ѡ��Ҫ�޸ĵ�ѡ�(Q��ȡ��)"NOR);
		input_to("view7");
		return;
	}
	if(arg=="q"||arg=="Q")
	{
		display();
		return;
	}
	if(!k=atoi(arg))
	{
		view7(0);
		return;
	}	
	text=explode(file,"\n");
	if(k>sizeof(text))
	{
		view7(0);
		return;
	}
	k--;
	write(YEL"��Ҫ�޸�(1)���ƻ���(2)���ӣ�"NOR);
	input_to("view8",text[k],k);
	return;
}	
void view8(string arg,string str,int k)
{		
	string *w=explode(str,"==@==");
	switch(arg) {
		case "1":
		write(HIC"����������:"NOR);
		input_to("view9",str,k,1);
		return;
		case "2":
		if(file_size(w[1])<0&&strsrch(w[1],"subdir")>-1)
		{
			write(HIG"����һ��Ŀ¼,���������ĵ�!\n"NOR);                         	view7(0);
			return;
		}
		write(HIC"�����������ĵ�:"NOR);
		input_to("view9",str,k,0);
		return;
	}
	view7(0);
	return;
}
void view9(string arg,string str,int i,int j)
{
	string file=read_file(find_file()),
	*text=explode(file,"\n"),
	*w=explode(str,"==@==");
	if(j) w[0]=arg;
	else {
		if(file_size(arg)<0)
		{
			write(HIR"û������ĵ�!\n"NOR);
			view8("2",str,i);
			return;
		}
		w[1]=arg;
	}
	text[i]=implode(w,"==@==");
	file=implode(text,"\n");
	write_file(find_file(),file,1);
	write("OK!\n");
	display();
	return;
}
void view3()
{
	string file,*text,str=find_file(),*w,msg,*t;
	int i,j;
	file=read_file(str);
	if(!file) 
	{
		write("���ϲɼ���......\n");
		return;
	}	
	text=explode(file,"\n");
	if(!j=sizeof(text)) 
	{
		write("���ϲɼ���......\n");
		return;
	}	
	t=({});
	file="";
	i=0;
	while(sizeof(text))	
	{
		w=explode(text[0],"==@==");
		file+=sprintf(HIC" ("BBLU +HIG"%2d"NOR +HIC")"HIW"��%|16s��"NOR,i+1,w[0]);
		if(i%3==2) file+="\n";
		text-=({text[0]});
		i++;
	}
	file+="\n";
	write(file);		
	return;
}
void view4()
{
	string file,*w,*text,str=find_file();
	int i,j,k,v;
	file=read_file(str);
	if(!file) 
	{
		write("���ϲɼ���......\n");
		return;
	}	
	text=explode(file,"\n");
	if(!j=sizeof(text)) 
	{
		write("���ϲɼ���......\n");
		return;
	}	
	for(file="",i=0;i<j;i++)	
	{
		w=explode(text[i],"==@==");
		file+=sprintf(HIC" (%2d)"HIW"��%|16s��%s"NOR,i+1,w[0],w[1]);
		if(i%2==1) file+="\n";
	}
	file+="\n";
	write(file);		
	return;
}
void view5(string arg)
{
	int k=atoi(arg),i,j;
	string *w,*text,file,t=this_player()->query_temp("select");
	file=find_file();
	file=read_file(file);
	if(!file) {
		write(HIR"û�������ļ�!\n"NOR);
		display();
		return;
	}
	if(arg=="q"||arg=="Q")
	{
		write(HIC"���أ�\n"NOR);
		display();
		return;
	}
	if(!k)
	{
		write(HIG"��������Ҫ�鿴������:"NOR);
		input_to("view5");
		return;
	}
	text=explode(file,"\n");
	if(j=sizeof(text)<k-1)
	{
		write(HIG"û������ļ�!\n"NOR);
		write(HIG"��������Ҫ�鿴������:"NOR);
		input_to("view5");
		return;
	}
	k--;
	w=explode(text[k],"==@==");	
	file=read_file(w[1]);
	if(file) {		
	        start_help(file,this_object());
	        return;
	}
	t=t+"/"+w[1];
	if(file_size(DIR+t+".h")<0)
	{
		write(HIG"û������ļ�!\n"NOR);
		write(HIG"��������Ҫ�鿴������:"NOR);
		input_to("view5");
		return;
	}	
	this_player()->set_temp("select",t);
	display();
	return;	
}
void delfile(string arg)
{
	int k=atoi(arg),v;
	string *text,*w,str=find_file(),file=read_file(str),t;		
	if(arg=="q"||arg=="Q")
	{
		display();
		return;
	}	
	if(k<1)
	{
		write(HIC"��Ҫɾ���ڼ�������:"NOR);
		input_to("delfile");
		return;	
	}
	text=explode(file,"\n");
	if(v=sizeof(text)<k)
	{
		write(HIG"û���������!\n");
		write(HIC"��Ҫɾ���ڼ�������:"NOR);
		input_to("delfile");
		return;	
	}	
	--k;
	w=explode(text[k],"==@==");
	text-=({text[k]});	
	file=implode(text,"\n");
	write_file(str,file,1);
	t=replace_string(find_file(),".h","");
	t=t+"/"+w[1]+".h";
	if(rm(t))
	{
	}
	write("OK!\n");
	display();
	return;
}			
varargs void display(object ob)
{
	int i;
	object me=this_player();
	string v,t=me->query_temp("select");
	if(!ob) ob=this_object();
	if(v=me->query_temp("memer"))
	{
		i=me->query(v);
		view_main_k();
		view1();
		write(view_msg(i,ob));
		view_main_1();
		write(YEL "\r����������ѡ��:"NOR);	
     		input_to((:confirm_p_choice:),ob);
     		return;
	}	
	if(t=="leaveword")
	{
		view6();
		write(YEL "\r����������ѡ��:"NOR);	
     		input_to((:confirm_l_choice:),this_player());
		return;
	}
	view_main();
	view3();
	view_main_1();
	write(BRED +HIC"(B)"NOR +BRED"���� "NOR);
	if(wiz_level(WIZLEVEL)<=wiz_level(me))
	write(BRED +HIC"  (A)"NOR+BRED"���� "HIC+BRED"(C)"NOR+BRED"�޸� "HIC+BRED"(D)"NOR
	+BRED"ɾ�� "HIC+BRED"(S)"NOR+BRED"�鿴 "HIC+BRED"(M)"NOR+BRED"�½�"NOR);
	write("\n");
	write(YEL "\r����������ѡ��:"NOR);	
	input_to((:confirm_choice:),this_player());	
}	
private void confirm_choice(string arg)
{
	object me=this_player();	
	string t=me->query_temp("select");
	string *text;
	int k=atoi(arg);
	int p;	     	
	if(k>0) 
	{
		view5(arg);
		return;
	}
     	switch(arg)
     	{
     		case "b":
     		text=explode(t,"/");
     		if(sizeof(text)<2)
     		{
     			main(me,0);
     			return;
     		}
     		text-=({text[sizeof(text)-1]});
     		t=implode(text,"/");
     		me->set_temp("select",t);
     		display();
     		return;     		
     		break;
     		case "c":
     		view7(0);
     		return;
     		break;
		case "a":
		if(wiz_level(me)<wiz_level(WIZLEVEL))
		{
			write(HIR"���Ȩ�޲��㣬�����޸�����ĵ�����\n");
			return;
		}
		write(HIC"�������������ƣ�"NOR);
		input_to("getname1");
		return;	
		break;
		case "d":
		if(wiz_level(me)<wiz_level(WIZLEVEL))
		{
			write(HIR"���Ȩ�޲��㣬�����޸�����ĵ�����\n");
			return;
		}
		write(HIC"��Ҫɾ���ڼ�������:"NOR"(��Q��ȡ��)");
		input_to("delfile");
		return;	
		break;		
		case "s":
		view_main();
		view4();
		view_main_1();
		write(BRED +HIC"(B)"NOR +BRED"���� "NOR);
		if(wiz_level(WIZLEVEL)<=wiz_level(me))
		write(BRED +HIC"  (A)"NOR+BRED"���� "HIC+BRED"(C)"NOR+BRED"�޸� "HIC+BRED"(D)"NOR
		+BRED"ɾ�� "HIC+BRED"(S)"NOR+BRED"�鿴 "HIC+BRED"(M)"NOR+BRED"�½�"NOR);
		write("\n");
		write(YEL "\r����������ѡ��:"NOR);	
		input_to((:confirm_choice:),me);	
		return;
		break;
		case "m":
		if(wiz_level(me)<wiz_level(WIZLEVEL))
		{
			write(HIR"���Ȩ�޲��㣬�����޸�����ĵ�����\n");
			return;
		}
		write(HIC"������Ŀ¼���ƣ�"NOR);
		input_to("getname3");
		return;
	}
	display();
	return;
}
void view6()
{
	int i,j,k;
	string *file,name,str="",msg;
	object ob;
	view_main();
	this_player()->delete_temp("memer");
	if(file_size(BOARDCENTER)>-1)
	{
		str=read_file(BOARDCENTER);
		write(str);		
	}
	else {	
		file=get_dir(BOARD+"*.c");	
		for(i=0;i<sizeof(file);i++)
		{			
			if(!ob=find_object(BOARD+file[i]))
			ob=load_object(BOARD+file[i]);
			if(!ob||!ob->query("board_id"))
			continue;
			name=ob->query("name");				
			name=replace_string(name,"���԰�","");
			name=replace_string(name,"���Բ�","");
			name=replace_string(name,"���Բ�","");
			name=replace_string(name,"����","");
			name=replace_string(name,"����","");
			name=replace_string(name,"����","");
			if(strlen(name)>16)
			name=name[0..15];
			destruct(ob);
			msg=sprintf(" ��"HIC +BBLU+"%2d"NOR+"��"+HIW+"��%|16s��"NOR,i+1,name);		
			str+=msg;
			write(msg);
			++j;
			if(j==3) 
			{
				j=0;
				write("\n");
				str+="\n";
			}	
		}  if(j==3) {
			write("\n");
			str+="\n";
		}		
		str+=sprintf(" ��"HIC +BBLU+"%2s"NOR+"��"+HIW+"��%|16s��\n"NOR,"B","�������˵�");		
		printf(" ��"HIC +BBLU+"%2s"NOR+"��"+HIW+"��%|16s��\n"NOR,"B","�������˵�");	
		write_file(BOARDCENTER,str,1);
	}		
	view_main_1();	
	input_to((:confirm_k_choice:),this_player());	
	return;
}
private void confirm_k_choice(string arg)
{
	int k=atoi(arg);
	string *file=get_dir(BOARD+"*.c"),dir;
	object ob;
	if(arg=="b")	
	{
		main(this_player(),0);
     		return;  
     	}
     	else if(!k)
     	{
     		write(HIC"����������ѡ��:"NOR);
     		input_to((:confirm_k_choice:),this_player());	
		return;
	}
	--k;
	dir=BOARD+file[k];
	if(!ob=find_object(dir))
	ob=load_object(dir);
	if(!ob||!ob->query("board_id"))
	{
		write(HIC"û��������԰�!\n����������ѡ��:"NOR);
     		input_to((:confirm_k_choice:),this_player());		
		return;
	}
	ob->restore();
	this_player()->set_temp("memer","post/"+file[k]);
	display(ob);
	return;
}
void getname3(string arg)
{	
	int k;
	string dir,t=this_player()->query_temp("select"),
	*text,msg,*w,file=read_file(find_file());
	if(!file) file="";
	if(!arg||arg=="")
	{
		write(HIC"������Ŀ¼���ƣ�"NOR);
		input_to("getname3");
		return;
	}
	if(arg=="q"||arg=="Q")
	{
		display();
		return;
	}		
	k=strlen(arg);
	if(k<2||k>16)
	{
		write(HIG"Ŀ¼��������������2��16����Ԫ֮�䣡\n"NOR);
		write(HIC"������Ŀ¼���ƣ�"NOR);
		input_to("getname3");
		return;
	}
	dir=replace_string(find_file(),".h","");
	mkdir(dir);
	for(k=0;;k++)
	{
		t="subdir"+k;
		msg=dir+"/"+t+".h";
		if(file&&strsrch(file,t)<0)		
		rm(msg);		
		if(file_size(msg)>-1)
		continue;
		break;
	}
	file+=arg+"==@=="+t+"\n";
	text=explode(file,"\n");
	file="";
	write_file(msg,"",1);
	while(sizeof(text))
	{
		msg=text[0];	
		text-=({msg});		
		w=explode(msg,"==@==");
		t=replace_string(find_file(),".h","");
		t=t+"/"+w[1]+".h";
		if(file_size(w[1])<0&&file_size(t)<0)
		continue;
		file+=msg+"\n";
	}
	write_file(find_file(),file,1);
	write("OK!\n");
	display();
	return;
}
