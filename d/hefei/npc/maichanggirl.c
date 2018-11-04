
inherit NPC;

int do_show();

void create()
{
   set_name("��������",({ "gu niang","niang","girl" }) );
   set("gender", "Ů��" );
   set("age", 18);
   set("long", "����һ�������Ĺ��\n");
       
   set("combat_exp", 10000);
   set("per", 25);
   
   set("inquiry",([
   	"����":"СŮ�Ӳ�֪��ʱ�����ҵ�һ�������ɾ�����",
   	"����":(:do_show:),
   	]));
   
   setup();
   add_money("coin", 50);
}

void init()
{

	::init();
	if(!living(this_object()))
		return;
	
	call_out("welcome",1);
	
}

void welcome()
{
 
switch(random(2)){
		case 0: 
			command("say ��λ�͹�����СŮ�Ӹ���λ����С����");
			break;
		case 1: 
			command("say ��ʱ�����ܹ�̫ƽ��Ҳ��СŮ�Ӽ޵�һ�����ɾ���");
		
}
remove_call_out("welcome");
return;
}

int do_show()
{
if(query("showing")){
	command("say �͹���ȵȣ�ū����׼�����ء�");
	return 1;
}
set("showing",1);
command("say ��Ȼ�͹�Ҫ�����Ҿͳ�һ�����͹������ɣ�");

call_out("do_show2",2,0);	

return 1;
	
}

string *poem=({
	"����˼��������",
	"����׷�ʪ��ޣ����깫�Ӹ�����"
	});

void do_show2(int i)
{
command("say "+poem[i]);
if(i>=1){
	command("say СŮ��ֻ�ǵ���ô�࣬�׳��ˣ�");
	delete("showing");
	return;
}
call_out("do_show2",2,i+1); 	
	
}
